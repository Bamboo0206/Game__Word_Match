#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WINSOCK2.H>   
#include <iostream> 
#include <string>
#include<ctime>
#include<windows.h>

//定义程序中使用的常量      
#define SERVER_ADDRESS "10.122.221.251" //服务器端IP地址      
#define PORT           52499         //服务器的端口号      
#define BUF_SIZE 1024				//收发缓冲区的大小 

#pragma comment(lib, "ws2_32.lib")      
using namespace std;

void game(SOCKET sclient);
void Multiplayer(SOCKET sclient);

int main()
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET)
	{
		printf("invalid socket!");
		return 0;
	}

	//远程服务器的地址信息
	SOCKADDR_IN serAddr;
	memset(&serAddr, 0, sizeof(SOCKADDR_IN));
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(PORT);
	serAddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		//		客户端socket   服务器端的地址   地址长度
	{  //连接失败 
		printf("connect error !");
		closesocket(sclient);
		return 0;
	}

	char data[BUF_SIZE] = { '\0' };
	while (true)
	{
		/*接收*/
		char recData[BUF_SIZE];
		int ret = recv(sclient, recData, BUF_SIZE, 0);
		if (ret > 0)
		{
			recData[ret] = '\0';
			cout << recData;

			

		}
		else if (ret <= 0)
		{
			cerr << "出错\n";
			break;
		}
		if (strcmp(recData, "成功创建对局。\n等待对手加入...\n") == 0)
		{
			/*接收:已找到对手。\n等待开局...*/
			ret = recv(sclient, recData, BUF_SIZE, 0);//继续或退出游戏
			recData[ret] = '\0';
			cout << recData;

			Multiplayer(sclient);
			recData[0] = '\0';
			continue;
		}
		if (strcmp(recData, "已找到对手。\n等待开局...\n") == 0)
		{
			Multiplayer(sclient);
			recData[0] = '\0';
			continue;
		}


		if (strcmp(data, "start_game") == 0)//下一次循环才会进入函数
		{
			int finish = 0;
			while (!finish)
			{
				game(sclient);

				/*接收*/
				ret = recv(sclient, recData, BUF_SIZE, 0);//继续或退出游戏
				recData[ret] = '\0';
				cout << recData;

				/*读输入*/
				cout << "Send>>>";
				cin >> finish;//继续0或退出1游戏
				getchar();
				//cin.getline(data, BUF_SIZE, '\n');
				data[0] = finish + '0'; data[1] = '\0';
				/*发送*/
				send(sclient, data, strlen(data), 0);

				/*接收：****第x关****/
				if (!finish)
				{
					ret = recv(sclient, recData, BUF_SIZE, 0);//继续或退出游戏
					recData[ret] = '\0';
					cout << recData;
				}

			}
			data[0] = '\0';
			continue;
		}

		/*读输入*/
		cout << "Send>>>";
		cin.getline(data, BUF_SIZE, '\n');
		
		/*发送*/
		send(sclient, data, strlen(data), 0);
		if (strcmp(data, "quit") == 0)
		{
			break;
		}
		
	}
	shutdown(sclient, SD_SEND);

	char recData[255];
	int ret = recv(sclient, recData, 255, 0);
	if (ret == 0)
		closesocket(sclient);
	WSACleanup();
	return 0;
}

void game(SOCKET sclient)
{
	int display_time, word_num_to_pass, error_chance;
	char recData[BUF_SIZE], word[100];
	int ret = recv(sclient, recData, BUF_SIZE, 0);
	sscanf(recData, "%d %d", &word_num_to_pass, &error_chance);

	/*开始游戏*/
	int word_passed = 0;
	while (word_passed < word_num_to_pass && error_chance >= 0)
	{
		ret = recv(sclient, recData, BUF_SIZE, 0);
		if (ret > 0)
		{
			recData[ret] = '\0';
			sscanf(recData, "%d %s", &display_time, word);
		}
		else if (ret <= 0)
		{
			cerr << "出错\n";
			return;
		}
		cout << "请记住这个单词（" << display_time << "毫秒后消失）："
			<< word;
		Sleep(display_time);


		cout << "\r                                                            ";
		cout << "\r请输入刚才出现的单词：";
		string input_word;
		/*待改：计时器*/
		clock_t start = clock();//启动计时器
		getline(cin, input_word);
		clock_t finish = clock();//关闭计时器
		double duration = (double)(finish - start) / CLOCKS_PER_SEC;//算时间
		cout << "用时" << (double)(finish - start) / CLOCKS_PER_SEC << "秒" << endl;
		

		char data[BUF_SIZE];
		if (input_word == word)//正确
		{
			cout << "输入单词正确\n";
			word_passed++;
			sprintf(data, "1\n%f", duration);
		}
		else//错误
		{
			sprintf(data, "0\n%f", duration);//回传结果

			cout << "输入单词错误\t刚才显示的单词是：" << word << endl;
			Sleep(2000);
			if (--error_chance == -1)
			{
				send(sclient, data, strlen(data), 0);
				break;
			}
			cout << "您还有" << error_chance << "次错误机会" << endl;
		}
		send(sclient, data, strlen(data), 0);
	}
}

void Multiplayer(SOCKET sclient)
{
	int display_time, word_num_to_pass;
	char recData[BUF_SIZE], word[100];

	/*接收：****第x关****/
	int ret = recv(sclient, recData, BUF_SIZE, 0);
	recData[ret] = '\0';
	cout << recData;

	/*接收word_num_to_pass*/
	recv(sclient, recData, BUF_SIZE, 0);
	sscanf(recData, "%d %d", &word_num_to_pass, &display_time);


	/*开始游戏*/
	int word_passed = 0;
	while (word_passed < word_num_to_pass )
	{
		/*接收单词和显示时间*/
		ret = recv(sclient, word, BUF_SIZE, 0);
		if (ret > 0)
		{
			word[ret] = '\0';
			//sscanf(recData, "%s", word);
		}
		else if (ret <= 0)
		{
			cerr << "出错\n";
			return;
		}

		/*显示*/
		cout << "请记住这个单词（" << display_time << "毫秒后消失）："
			<< word;
		Sleep(display_time);

		cout << "\r                                                            ";
		cout << "\r请输入刚才出现的单词：";
		string input_word;
		/*计时器*/
		clock_t start = clock();//启动计时器
		getline(cin, input_word);
		clock_t finish = clock();//关闭计时器
		double duration = (double)(finish - start) / CLOCKS_PER_SEC;//算时间
		cout << "用时" << (double)(finish - start) / CLOCKS_PER_SEC << "秒" << endl;
	

		char data[BUF_SIZE];
		if (input_word == word)//正确
		{
			cout << "输入单词正确\n";
			sprintf(data, "1\n%f", duration);
		}
		else//错误
		{
			sprintf(data, "0\n%f", duration);//回传结果

			cout << "输入单词错误\t刚才显示的单词是：" << word << endl;
		}
		send(sclient, data, strlen(data), 0);
		word_passed++;
	}
}