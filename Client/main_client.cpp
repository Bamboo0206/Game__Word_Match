#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WINSOCK2.H>   
#include <iostream> 
#include <string>

//定义程序中使用的常量      
#define SERVER_ADDRESS "10.122.221.251" //服务器端IP地址      
#define PORT           51500         //服务器的端口号      
#define BUF_SIZE 1024				//收发缓冲区的大小 

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

	while (true)
	{
		/*接收*/
		char recData[BUF_SIZE];
		int ret = recv(sclient, recData, BUF_SIZE, 0);
		if (ret > 0)
		{
			recData[ret] = '\0';
			cout << recData << endl;
		}
		else if (ret <= 0)
		{
			cerr << "出错\n";
			break;
		}


		/*读输入*/
		cout << "Send>>>";
		char data[BUF_SIZE] = { '\0' };
		cin.getline(data, BUF_SIZE, '\n');
		////输入正确性检验
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

		/*发送*/
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