#include"header.h"
#include"class.h"
#include"function_declaration.h"

/*ȫ�ֱ���*/
vector<player> v_player;//����player
vector<test_maker> v_test_maker;//����test_maker
vector<string> word_set;//���ʼ���
vector<sysInfo> v_sysInfo;//ÿ���߳�һ���������ڴ洢ϵͳ��Ϣ�͵�ǰϵͳ�û���

#define PORT           51500    //�˿ں�
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

	//�����׽���
	SOCKET sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sListen == INVALID_SOCKET)
	{
		cout << "socket error!" << endl;
		return 0;
	}

	//��IP�Ͷ˿�
	SOCKADDR_IN local;
	local.sin_family = AF_INET;
	local.sin_port = htons(PORT);
	//#define INADDR_ANY              (ULONG)0x00000000
	local.sin_addr.s_addr = htonl(INADDR_ANY);

	if (bind(sListen, (struct sockaddr *) &local, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
		//	socket		�󶨸�socket�ĵ�ַ�����ص�ַ��  ��ַ�ĳ���
	{
		cout << "bind error!" << endl;
	}

	if (listen(sListen, 5) == SOCKET_ERROR)
		//����sListen   sListen�������Ŷӵ���������
		/*ÿ����һ���ͻ���connect�ˣ�listen�Ķ����оͼ���һ�����ӣ�
		ÿ����������accept�ˣ��ʹ�listen�Ķ�����ȡ��һ�����ӣ�
		ת��һ��ר�������������ݵ�socket��accept�����ķ���ֵ��*/
	{
		cout << "listen error!\n";
		return 0;
	}

	/*��ʼ�� �ʿ⡢��ע����û�*/
	srand((unsigned int)time(NULL));
	read_wordlib();
	read_player();
	read_test_maker();

	/*ѭ��*/
	bool quit = false;
	bool connected = false;
	while (true)
	{
		/*accept()*/
		cout << "waiting for connect...\n";
		SOCKET *sClient = new SOCKET;
		SOCKADDR_IN clientaddr;
		int iaddrSize = sizeof(SOCKADDR_IN);
		*sClient = accept(sListen, (struct sockaddr *) &clientaddr, &iaddrSize);//�����ӻῨ������
		if (*sClient == INVALID_SOCKET)
		{
			cout << "accept error!\n";
		}
		cout << "Accept a connection:" << inet_ntoa(clientaddr.sin_addr) << ":"
			<< ntohs(clientaddr.sin_port) << endl;
		HANDLE hThread=(HANDLE*)_beginthreadex(NULL, 0, newClient, sClient, 0, NULL);
		CloseHandle(hThread);
	}

	return 0;
}


unsigned __stdcall newClient(void* pArguments)
{
	SOCKET sClient = *((SOCKET*)pArguments);

	/*��ʼ�����������*/
	vector<player>::iterator it_user_player = v_player.end();//���̵߳�ǰϵͳ�û�player
	vector<test_maker>::iterator it_user_test_maker = v_test_maker.end();//���̵߳�ǰϵͳ�û�test_maker
	string username_player;
	string username_test_maker;

	sysInfo sysinfo;//��׼io�ض���
	v_sysInfo.push_back(sysinfo);

	/*����*/
	char sendData[BUF_SIZE] = "Welcome to Word Match Game.\nInput anything to continue...\n";
	send(sClient, sendData, strlen(sendData), 0);
	/*����*/
	char recData[BUF_SIZE];
	int ret = recv(sClient, recData, BUF_SIZE, 0);
	if (ret > 0)
	{
		recData[ret] = '\0';
		cerr << recData << endl;
	}

	/*����*/
	string option;
	while (true)
	{
		/*����ѡ��*/
		cout << "*****************************************\n"
			<< "ע�᣺sign_up\n"
			<< "��½��log_in\n"
			<< "�����ߣ���ʼ��Ϸ��start_game\n"
			<< "�����ߣ��������ʣ�add_word\n"
			<< "���а�rank\n"
			<< "���Ҵ����ߣ�search_player\n"
			<< "���ҳ����ߣ�search_test_maker\n"
			<< "�ǳ���log_out\n"
			<< "�˳�����quit\n"
			<< "*****************************************\n"
			<< "��ѡ�������\n\0";
		sysinfo.oss.getline(sendData+1, BUF_SIZE-1, '\0');
		sendData[0] = 1;//0Ϊclient�������գ�1Ϊclient����
		send(sClient, sendData, strlen(sendData), 0);


		//��������
		//char szMessage[MSGSIZE];
		ret = recv(sClient, recData, BUF_SIZE, 0);
		if (ret > 0)
		{
			recData[ret] = '\0';
			if(DEBUG) cerr << recData << endl;

		}
		if (ret == 0)/*�ر�*/
		{
			shutdown(sClient, SD_SEND);
			closesocket(sClient);//�����رջ᷵��0
			break;
		}
		if (ret < 0)/*�������ر�*///??????����
		{
			cerr << "client�������ر�\n";
			break;
		}

		/*����*/
		string option(recData);
		/*ע��*/
		if (option == "sign_up")
		{
			sign_up();
		}
		/*��½*///����ѵ�½�����
		else if (option == "log_in")
		{
			log_in(username_player,username_test_maker);
		}
		/*��ʼ��Ϸ*/
		else if (option == "start_game")
		{
			/*����Ƿ��½*/
			if (username_player.length() == 0)
			//if (it_user_player == v_player.end())
			{
				cout << "���ȵ�½\n";
			}
			else
			{
				start_game(username_player);
			}
		}
		/*��������*/
		else if (option == "add_word")
		{
			/*����Ƿ��½*/
			if(username_test_maker.length()==0)
			//if (it_user_test_maker == v_test_maker.end())//��������
			{
				cout << "���ȵ�½\n";
			}
			else
			{
				add_word(username_test_maker);
			}
		}

		/*�ǳ�*/
		else if (option == "log_out")
		{
			log_out(username_player,username_test_maker);
		}
		/*���а�*/
		else if (option == "rank")
		{
			cout << "��ѡ��Ҫ�鿴�����а�player/test_maker����\n";
			string choice;
			cin >> choice;
			if (choice == "player")rank_player();
			else if (choice == "test_maker")rank_test_maker();
			else cout << "�Ƿ�����" << endl;
		}

		/*����ɫ���Բ�ѯ*/
		else if (option == "search_player")
		{
			search_player();
		}
		else if (option == "search_test_maker")
		{
			search_test_maker();
		}

		/*�˳�ϵͳ ��Ҫд�ļ�*/
		else if (option == "quit")
		{
			write_participants();
			break;
		}
		else
		{
			cout << "�Ƿ�����\n" ;
			sysinfo.oss.getline(sendData + 1, BUF_SIZE - 1, '\0');
			sendData[0] = 1;//0Ϊclient�������գ�1Ϊclient����
			send(sClient, sendData, strlen(sendData), 0);
		}
	}

	cout << "disconnected\n";
	delete &sClient;
	_endthreadex(0);
	return 0;
}