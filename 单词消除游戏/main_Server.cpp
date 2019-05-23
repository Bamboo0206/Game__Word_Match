#include"header.h"
#include"class.h"
#include"function_declaration.h"

/*全局变量*/
vector<player> v_player;//所有player
vector<test_maker> v_test_maker;//所有test_maker
vector<string> word_set;//单词集合
vector<sysInfo> v_sysInfo;//每个线程一个对象，用于存储系统信息和当前系统用户等
vector<room> v_room;//游戏房间集合

#define PORT           52499    //端口号
#define MSGSIZE        1024    


#pragma comment(lib, "ws2_32.lib")      

using namespace std;

unsigned __stdcall newClient(void* pArguments);

int main()
{

	WORD socketVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(socketVersion, &wsaData) != 0)
	{
		return 0;
	}

	//创建套接字
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sListen == INVALID_SOCKET)
	{
		cout << "socket error!" << endl;
		return 0;
	}

	//绑定IP和端口
	SOCKADDR_IN local;
	local.sin_family = AF_INET;
	local.sin_port = htons(PORT);
	//#define INADDR_ANY              (ULONG)0x00000000
	local.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sListen, (struct sockaddr *) &local, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
		//	socket		绑定给socket的地址（本地地址）  地址的长度
	{
		cout << "bind error!" << endl;
	}

	if (listen(sListen, 5) == SOCKET_ERROR)
		//监听sListen   sListen最大可以排队的连接数量
		/*每当有一个客户端connect了，listen的队列中就加入一个连接，
		每当服务器端accept了，就从listen的队列中取出一个连接，
		转成一个专门用来传输数据的socket（accept函数的返回值）*/
	{
		cout << "listen error!\n";
		return 0;
	}

	/*初始化 词库、已注册的用户*/
	srand((unsigned int)time(NULL));
	read_wordlib();
	read_player();
	read_test_maker();

	/*循环*/
	bool quit = false;
	bool connected = false;
	while (true)
	{
		/*accept()*/
		cout << "waiting for connect...\n";
		SOCKET *sClient = new SOCKET;
		SOCKADDR_IN *clientaddr = new SOCKADDR_IN;
		int iaddrSize = sizeof(SOCKADDR_IN);
		*sClient = accept(sListen, (struct sockaddr *) clientaddr, &iaddrSize);//无连接会卡在这里
		if (*sClient == INVALID_SOCKET)
		{
			cout << "accept error!\n";
		}
		cout << "Accept a connection:" << inet_ntoa(clientaddr->sin_addr) << ":"
			<< ntohs(clientaddr->sin_port) << endl;
		SKT_INFO *sktInfo = new SKT_INFO;
		sktInfo->skt = sClient;
		sktInfo->addr = clientaddr;
		HANDLE hThread=(HANDLE*)_beginthreadex(NULL, 0, newClient, sktInfo, 0, NULL);
		CloseHandle(hThread);
	}

	return 0;
}


unsigned __stdcall newClient(void* pArguments)
{
	SKT_INFO *sktInfo = (SKT_INFO *)pArguments;
	SOCKET sClient = *(sktInfo->skt);

	/*初始化：定义变量*/
	vector<player>::iterator it_user_player = v_player.end();//本线程当前系统用户player
	vector<test_maker>::iterator it_user_test_maker = v_test_maker.end();//本线程当前系统用户test_maker
	string username_player;
	string username_test_maker;

	{
		sysInfo sysinfo(sktInfo);
		v_sysInfo.push_back(sysinfo);//深拷贝。
		vector<sysInfo>::iterator it_sysInfo = v_sysInfo.end() - 1;
		////标准io重定向
		//cout.rdbuf(it_sysInfo->oss.rdbuf());//分别与cout,cin绑定
		//cin.rdbuf(it_sysInfo->iss.rdbuf());
	}

	/*发送*/
	//char sendData[BUF_SIZE] = "Welcome to Word Match Game.\nInput anything to continue...\n\0";

	vector<sysInfo>::iterator it_sysInfo;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != sktInfo->addr->sin_port; it_sysInfo++);
	it_sysInfo->oss << "Welcome to Word Match Game.\nInput anything to continue...\n";
	mySend(sktInfo->addr->sin_port);

	//send(sClient, sendData, strlen(sendData), 0);
	/*接收*/
	char recData[BUF_SIZE];
	int ret = recv(sClient, recData, BUF_SIZE, 0);
	if (ret > 0)
	{
		recData[ret] = '\0';
		cerr << recData << endl;
	}

	/*运行*/
	string option;
	while (true)
	{
		/*发送选项*/

		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != sktInfo->addr->sin_port; it_sysInfo++);
		it_sysInfo->oss << "*****************************************\n"
			<< "注册：sign_up\n"
			<< "登陆：log_in\n"
			<< "闯关者：开始游戏：start_game\n"
			<< "出题者：新增单词：add_word\n"
			<< "排行榜：rank\n"
			<< "查找闯关者：search_player\n"
			<< "查找出题者：search_test_maker\n"
			<< "登出：log_out\n"
			<< "退出程序：quit\n"
			<< "*****************************************\n"
			<< "请选择操作：\n\0";
		//sysinfo.oss.getline(sendData+1, BUF_SIZE-1, '\0');
		//sendData[0] = 1;//0为client继续接收，1为client发送
		//send(sClient, sendData, strlen(sendData), 0);
		mySend(sktInfo->addr->sin_port);


		////接收数据
		////char szMessage[MSGSIZE];
		//ret = recv(sClient, recData, BUF_SIZE, 0);
		//if (ret > 0)
		//{
		//	recData[ret] = '\0';
		//	if(DEBUG) cerr << recData << endl;

		//}
		//if (ret == 0)/*关闭*/
		//{
		//	cerr << "Disconected:" << inet_ntoa(sktInfo->addr->sin_addr) << ":"
		//		<< ntohs(sktInfo->addr->sin_port) << endl;
		//	shutdown(sClient, SD_SEND);
		//	closesocket(sClient);//正常关闭会返回0
		//	break;
		//}
		//if (ret < 0)/*不正常关闭*///??????待改
		//{
		//	cerr << "client不正常关闭:" << inet_ntoa(sktInfo->addr->sin_addr) << ":"
		//		<< ntohs(sktInfo->addr->sin_port) << endl;
		//	break;
		//}

		/*运行*/
		string option/*(recData)*/;
		myRecv(sktInfo->addr->sin_port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != sktInfo->addr->sin_port; it_sysInfo++);
		it_sysInfo->iss >> option;

		/*注册*/
		if (option == "sign_up")
		{
			sign_up(sktInfo->addr->sin_port);
		}
		/*登陆*///如果已登陆的情况
		else if (option == "log_in")
		{
			log_in(username_player, username_test_maker, sktInfo->addr->sin_port);
		}
		/*开始游戏*/
		else if (option == "start_game")
		{
			/*检测是否登陆*/
			if (username_player.length() == 0)
				//if (it_user_player == v_player.end())
			{
				for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != sktInfo->addr->sin_port; it_sysInfo++);
				it_sysInfo->oss << "请先登陆\n";
			}
			else
			{
				start_game(username_player, sktInfo->addr->sin_port);
			}
		}
		/*新增单词*/
		else if (option == "add_word")
		{
			/*检测是否登陆*/
			if (username_test_maker.length() == 0)
				//if (it_user_test_maker == v_test_maker.end())//？？？？
			{
				for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != sktInfo->addr->sin_port; it_sysInfo++);
				it_sysInfo->oss << "请先登陆\n";
			}
			else
			{
				add_word(username_test_maker, sktInfo->addr->sin_port);
			}
		}

		/*登出*/
		else if (option == "log_out")
		{
			log_out(username_player, username_test_maker, sktInfo->addr->sin_port);
		}
		/*排行榜*/
		else if (option == "rank")
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != sktInfo->addr->sin_port; it_sysInfo++);
			it_sysInfo->oss << "请选择要查看的排行榜（player/test_maker）：\n";
			string choice;
			mySend(sktInfo->addr->sin_port);
			myRecv(sktInfo->addr->sin_port);
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != sktInfo->addr->sin_port; it_sysInfo++);
			it_sysInfo->iss >> choice;
			if (choice == "player")rank_player(sktInfo->addr->sin_port);
			else if (choice == "test_maker")rank_test_maker(sktInfo->addr->sin_port);
			else
			{
				for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != sktInfo->addr->sin_port; it_sysInfo++);
				it_sysInfo->oss << "非法输入" << endl;
			}
		}

		/*按角色属性查询*/
		else if (option == "search_player")
		{
			search_player(sktInfo->addr->sin_port);
		}
		else if (option == "search_test_maker")
		{
			search_test_maker(sktInfo->addr->sin_port);
		}

		/*退出系统 需要写文件*/
		else if (option == "quit")
		{
			write_participants();
			break;
		}
		else
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != sktInfo->addr->sin_port; it_sysInfo++);
			it_sysInfo->oss << "非法输入\n";
			//sysinfo.oss.getline(sendData + 1, BUF_SIZE - 1, '\0');
			//sendData[0] = 1;//0为client继续接收，1为client发送
			//send(sClient, sendData, strlen(sendData), 0);
		}
	}


	cerr << "Disconected:" << inet_ntoa(sktInfo->addr->sin_addr) << ":"
		<< ntohs(sktInfo->addr->sin_port) << endl;
	shutdown(sClient, SD_SEND);
	closesocket(sClient);//正常关闭会返回0

	//cout << "disconnected\n";
	delete sktInfo->skt;
	_endthreadex(0);
	return 0;
}