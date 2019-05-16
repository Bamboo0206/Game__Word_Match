#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WINSOCK2.H> 
#include <iostream>
#include <windows.h>
#include <process.h> 
#include <iostream>     

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
	{<< "
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

	/*����*/
	string option;
	while (true)
	{
		/*����ѡ��*/
		const char *sendData = "*****************************************\nע�᣺sign_up\n��½��log_in\n�����ߣ���ʼ��Ϸ��start_game\n�����ߣ��������ʣ�add_word\n���а�rank\n���Ҵ����ߣ�search_player\n���ҳ����ߣ�search_test_maker\n�ǳ���log_out\n�˳�����quit\n*****************************************\n��ѡ�������\n";
		
		send(sClient, sendData, strlen(sendData), 0);


		//��������
		char szMessage[MSGSIZE];
		int ret = recv(sClient, szMessage, MSGSIZE, 0);
		if (ret > 0)
		{
			szMessage[ret] = '\0';
			cout << szMessage << endl;
		}
		if (ret == 0)/*�ر�*/
		{
			shutdown(sClient, SD_SEND);
			closesocket(sClient);//�����رջ᷵��0
			break;
		}
		//if (ret < 0)/*�������ر�*///??????����

		string option(szMessage);
		/*ע��*/
		if (option == "sign_up")
		{
			sign_up();
		}
		/*��½*///����ѵ�½�����
		else if (option == "log_in")
		{
			log_in();
		}
		/*��ʼ��Ϸ*/
		else if (option == "start_game")
		{
			/*����Ƿ��½*/
			if (it_user_player == v_player.end())
			{
				cout << "���ȵ�½\n";
			}
			else
			{
				start_game();
			}
		}
		/*��������*/
		else if (option == "add_word")
		{
			/*����Ƿ��½*/
			if (it_user_test_maker == v_test_maker.end())//��������
			{
				cout << "���ȵ�½\n";
			}
			else
			{
				add_word();
			}
		}

		/*�ǳ�*/
		else if (option == "log_out")
		{
			log_out();
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
			cout << "�Ƿ�����" << endl;

		//��������
		const char *sendData = NULL;
		sendData = "Server: Got it";
		send(sClient, sendData, strlen(sendData), 0);
	}

	cout << "disconnected\n";
	delete &sClient;
	_endthreadex(0);
	return 0;
}