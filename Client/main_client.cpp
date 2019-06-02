#define _CRT_SECURE_NO_WARNINGS
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WINSOCK2.H>   
#include <iostream> 
#include <string>
#include<ctime>
#include<windows.h>

//���������ʹ�õĳ���      
#define SERVER_ADDRESS "10.122.221.251" //��������IP��ַ      
#define PORT           52499         //�������Ķ˿ں�      
#define BUF_SIZE 1024				//�շ��������Ĵ�С 

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

	char data[BUF_SIZE] = { '\0' };
	while (true)
	{
		/*����*/
		char recData[BUF_SIZE];
		int ret = recv(sclient, recData, BUF_SIZE, 0);
		if (ret > 0)
		{
			recData[ret] = '\0';
			cout << recData;

			

		}
		else if (ret <= 0)
		{
			cerr << "����\n";
			break;
		}
		if (strcmp(recData, "�ɹ������Ծ֡�\n�ȴ����ּ���...\n") == 0)
		{
			/*����:���ҵ����֡�\n�ȴ�����...*/
			ret = recv(sclient, recData, BUF_SIZE, 0);//�������˳���Ϸ
			recData[ret] = '\0';
			cout << recData;

			Multiplayer(sclient);
			recData[0] = '\0';
			continue;
		}
		if (strcmp(recData, "���ҵ����֡�\n�ȴ�����...\n") == 0)
		{
			Multiplayer(sclient);
			recData[0] = '\0';
			continue;
		}


		if (strcmp(data, "start_game") == 0)//��һ��ѭ���Ż���뺯��
		{
			int finish = 0;
			while (!finish)
			{
				game(sclient);

				/*����*/
				ret = recv(sclient, recData, BUF_SIZE, 0);//�������˳���Ϸ
				recData[ret] = '\0';
				cout << recData;

				/*������*/
				cout << "Send>>>";
				cin >> finish;//����0���˳�1��Ϸ
				getchar();
				//cin.getline(data, BUF_SIZE, '\n');
				data[0] = finish + '0'; data[1] = '\0';
				/*����*/
				send(sclient, data, strlen(data), 0);

				/*���գ�****��x��****/
				if (!finish)
				{
					ret = recv(sclient, recData, BUF_SIZE, 0);//�������˳���Ϸ
					recData[ret] = '\0';
					cout << recData;
				}

			}
			data[0] = '\0';
			continue;
		}

		/*������*/
		cout << "Send>>>";
		cin.getline(data, BUF_SIZE, '\n');
		
		/*����*/
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

	/*��ʼ��Ϸ*/
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
			cerr << "����\n";
			return;
		}
		cout << "���ס������ʣ�" << display_time << "�������ʧ����"
			<< word;
		Sleep(display_time);


		cout << "\r                                                            ";
		cout << "\r������ղų��ֵĵ��ʣ�";
		string input_word;
		/*���ģ���ʱ��*/
		clock_t start = clock();//������ʱ��
		getline(cin, input_word);
		clock_t finish = clock();//�رռ�ʱ��
		double duration = (double)(finish - start) / CLOCKS_PER_SEC;//��ʱ��
		cout << "��ʱ" << (double)(finish - start) / CLOCKS_PER_SEC << "��" << endl;
		

		char data[BUF_SIZE];
		if (input_word == word)//��ȷ
		{
			cout << "���뵥����ȷ\n";
			word_passed++;
			sprintf(data, "1\n%f", duration);
		}
		else//����
		{
			sprintf(data, "0\n%f", duration);//�ش����

			cout << "���뵥�ʴ���\t�ղ���ʾ�ĵ����ǣ�" << word << endl;
			Sleep(2000);
			if (--error_chance == -1)
			{
				send(sclient, data, strlen(data), 0);
				break;
			}
			cout << "������" << error_chance << "�δ������" << endl;
		}
		send(sclient, data, strlen(data), 0);
	}
}

void Multiplayer(SOCKET sclient)
{
	int display_time, word_num_to_pass;
	char recData[BUF_SIZE], word[100];

	/*���գ�****��x��****/
	int ret = recv(sclient, recData, BUF_SIZE, 0);
	recData[ret] = '\0';
	cout << recData;

	/*����word_num_to_pass*/
	recv(sclient, recData, BUF_SIZE, 0);
	sscanf(recData, "%d %d", &word_num_to_pass, &display_time);


	/*��ʼ��Ϸ*/
	int word_passed = 0;
	while (word_passed < word_num_to_pass )
	{
		/*���յ��ʺ���ʾʱ��*/
		ret = recv(sclient, word, BUF_SIZE, 0);
		if (ret > 0)
		{
			word[ret] = '\0';
			//sscanf(recData, "%s", word);
		}
		else if (ret <= 0)
		{
			cerr << "����\n";
			return;
		}

		/*��ʾ*/
		cout << "���ס������ʣ�" << display_time << "�������ʧ����"
			<< word;
		Sleep(display_time);

		cout << "\r                                                            ";
		cout << "\r������ղų��ֵĵ��ʣ�";
		string input_word;
		/*��ʱ��*/
		clock_t start = clock();//������ʱ��
		getline(cin, input_word);
		clock_t finish = clock();//�رռ�ʱ��
		double duration = (double)(finish - start) / CLOCKS_PER_SEC;//��ʱ��
		cout << "��ʱ" << (double)(finish - start) / CLOCKS_PER_SEC << "��" << endl;
	

		char data[BUF_SIZE];
		if (input_word == word)//��ȷ
		{
			cout << "���뵥����ȷ\n";
			sprintf(data, "1\n%f", duration);
		}
		else//����
		{
			sprintf(data, "0\n%f", duration);//�ش����

			cout << "���뵥�ʴ���\t�ղ���ʾ�ĵ����ǣ�" << word << endl;
		}
		send(sclient, data, strlen(data), 0);
		word_passed++;
	}
}