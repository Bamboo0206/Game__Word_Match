#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WINSOCK2.H>   
#include <iostream> 
#include <string>

//���������ʹ�õĳ���      
#define SERVER_ADDRESS "10.122.221.251" //��������IP��ַ      
#define PORT           51500         //�������Ķ˿ں�      
#define BUF_SIZE 1024				//�շ��������Ĵ�С 

#pragma comment(lib, "ws2_32.lib")      
using namespace std;
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

	//Զ�̷������ĵ�ַ��Ϣ
	SOCKADDR_IN serAddr;
	memset(&serAddr, 0, sizeof(SOCKADDR_IN));
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(PORT);
	serAddr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		//		�ͻ���socket   �������˵ĵ�ַ   ��ַ����
	{  //����ʧ�� 
		printf("connect error !");
		closesocket(sclient);
		return 0;
	}

	while (true)
	{
		/*����*/
		char recData[BUF_SIZE];
		int ret = recv(sclient, recData, BUF_SIZE, 0);
		if (ret > 0)
		{
			recData[ret] = '\0';
			cout << recData << endl;
		}
		else if (ret <= 0)
		{
			cerr << "����\n";
			break;
		}


		/*������*/
		cout << "Send>>>";
		char data[BUF_SIZE] = { '\0' };
		cin.getline(data, BUF_SIZE, '\n');
		////������ȷ�Լ���
		//while (! && data[0] != '\0'))
		//{
		//	memset(data, 0, sizeof(data));
		//	cin.clear();
		//	cin.ignore(100, '\n');
		//}
		if (strcmp(data, "quit") == 0)
		{
			break;
		}

		/*����*/
		send(sclient, data, strlen(data), 0);
		

		if (strcmp(data, "start_game") == 0)
		{

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