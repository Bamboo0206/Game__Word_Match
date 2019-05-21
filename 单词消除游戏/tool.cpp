#include"header.h"
#include"variable.h"

void locate_player(string name, vector<player>::iterator &it_user_player)//ʹ������ָ��name��player
{
	for (vector<player>::iterator it = v_player.begin(); it != v_player.end(); it++)
	{
		if (it->show_name() == name)
		{
			it_user_player = it;
			break;
		}
	}
}

void locate_test_maker(string name, vector<test_maker>::iterator &it_user_test_maker)
{
	for (vector<test_maker>::iterator it = v_test_maker.begin(); it != v_test_maker.end(); it++)
	{
		if (it->show_name() == name)
		{
			it_user_test_maker = it;
			break;
		}
	}
}

void print_player(string &username_player)
{
	vector<player>::iterator it_user_player;
	locate_player(username_player, it_user_player);
	cout << "name:" << it_user_player->show_name() << '\t'
		<< "level:" << it_user_player->show_level() << '\t'
		<< "EXP:" << it_user_player->show_EXP() << '\t'
		<< "ͨ����:" << it_user_player->show_pass_count() << endl;
}
void print_test_maker(string &username_test_maker)
{
	vector<test_maker>::iterator it_user_test_maker;
	cout << "name:" << it_user_test_maker->show_name() << '\t'
		<< "level:" << it_user_test_maker->show_level() << '\t'
		<< "EXP:" << it_user_test_maker->show_EXP() << '\t'
		<< "���뵥����:" << it_user_test_maker->show_word_num() << endl;
}


/*������ȷ�Լ��飬cin�������򷵻�true*/
bool cin_error_and_repair()
{
	if (!cin)
	{
		cerr << "input error!\n";
		cin.clear();
		cin.ignore(99999, '\n');//�����������з����������е���������
		return true;
	}
	else
		return false;
}

/*����*/
/*���ݰ���0λΪflag*/
void mySend(char flag/*0Ϊclient��������*/, unsigned short int port)
{
	vector<sysInfo>::iterator it;
	for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->ClientAddr->sin_port != port; it++);//ͨ��port�ҵ���ȫ�ֱ���
	it->oss.getline(it->sendData + 1, BUF_SIZE - 1, '\0');//��oss��������ݿ�����sendData�������\0��β�����ݰ���û��\0
	it->sendData[0] = flag;//0Ϊclient�������գ�1Ϊclient����
	send(*(it->sClient), it->sendData, strlen(it->sendData), 0);//��������
}

void mySend(unsigned short int port)
{
	vector<sysInfo>::iterator it;
	for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->ClientAddr->sin_port != port; it++);//ͨ��port�ҵ���ȫ�ֱ���
	it->oss.getline(it->sendData, BUF_SIZE, '\0');//��oss��������ݿ�����sendData�������\0��β�����ݰ���û��\0
	//it->oss >> it->sendData;
	send(*(it->sClient), it->sendData, strlen(it->sendData), 0);//��������
	it->oss.str("");//�������getline�ƺ���û�аѶ���ȡ�ߣ�
	it->oss.clear();
}
void myRecv(unsigned short int port)
{

	vector<sysInfo>::iterator it;
	for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->ClientAddr->sin_port != port; it++);//ͨ��port�ҵ���ȫ�ֱ���
	
	int ret = recv(*(it->sClient), it->recData, BUF_SIZE, 0);
	if (ret > 0)
	{
		it->recData[ret] = '\0';
		if (DEBUG) cerr << it->recData << endl;

	}
	if (ret == 0)/*�ر�*/
	{
		cerr << "Disconected:" << inet_ntoa(it->ClientAddr->sin_addr) << ":"
			<< ntohs(it->ClientAddr->sin_port) << endl;
		shutdown(*(it->sClient), SD_SEND);
		closesocket(*(it->sClient));//�����رջ᷵��0
	}
	if (ret < 0)/*�������ر�*///??????����
	{
		cerr << "Disconected:" << inet_ntoa(it->ClientAddr->sin_addr) << ":"
			<< ntohs(it->ClientAddr->sin_port) << endl;
	}
	it->iss.str(it->recData);//����������
	it->iss.clear();//????
	cin.clear();
}