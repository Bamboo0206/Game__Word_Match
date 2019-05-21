#include"header.h"
#include"variable.h"

void locate_player(string name, vector<player>::iterator &it_user_player)//使迭代器指向name的player
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
		<< "通关数:" << it_user_player->show_pass_count() << endl;
}
void print_test_maker(string &username_test_maker)
{
	vector<test_maker>::iterator it_user_test_maker;
	cout << "name:" << it_user_test_maker->show_name() << '\t'
		<< "level:" << it_user_test_maker->show_level() << '\t'
		<< "EXP:" << it_user_test_maker->show_EXP() << '\t'
		<< "输入单词数:" << it_user_test_maker->show_word_num() << endl;
}


/*输入正确性检验，cin出问题则返回true*/
bool cin_error_and_repair()
{
	if (!cin)
	{
		cerr << "input error!\n";
		cin.clear();
		cin.ignore(99999, '\n');//放弃包含换行符的输入流中的所有内容
		return true;
	}
	else
		return false;
}

/*发送*/
/*数据包第0位为flag*/
void mySend(char flag/*0为client继续接收*/, unsigned short int port)
{
	vector<sysInfo>::iterator it;
	for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->ClientAddr->sin_port != port; it++);//通过port找到该全局变量
	it->oss.getline(it->sendData + 1, BUF_SIZE - 1, '\0');//将oss流里的数据拷贝到sendData数组里，以\0结尾（数据包里没有\0
	it->sendData[0] = flag;//0为client继续接收，1为client发送
	send(*(it->sClient), it->sendData, strlen(it->sendData), 0);//发送数据
}

void mySend(unsigned short int port)
{
	vector<sysInfo>::iterator it;
	for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->ClientAddr->sin_port != port; it++);//通过port找到该全局变量
	it->oss.getline(it->sendData, BUF_SIZE, '\0');//将oss流里的数据拷贝到sendData数组里，以\0结尾（数据包里没有\0
	//it->oss >> it->sendData;
	send(*(it->sClient), it->sendData, strlen(it->sendData), 0);//发送数据
	it->oss.str("");//清空流（getline似乎并没有把东西取走？
	it->oss.clear();
}
void myRecv(unsigned short int port)
{

	vector<sysInfo>::iterator it;
	for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->ClientAddr->sin_port != port; it++);//通过port找到该全局变量
	
	int ret = recv(*(it->sClient), it->recData, BUF_SIZE, 0);
	if (ret > 0)
	{
		it->recData[ret] = '\0';
		if (DEBUG) cerr << it->recData << endl;

	}
	if (ret == 0)/*关闭*/
	{
		cerr << "Disconected:" << inet_ntoa(it->ClientAddr->sin_addr) << ":"
			<< ntohs(it->ClientAddr->sin_port) << endl;
		shutdown(*(it->sClient), SD_SEND);
		closesocket(*(it->sClient));//正常关闭会返回0
	}
	if (ret < 0)/*不正常关闭*///??????待改
	{
		cerr << "Disconected:" << inet_ntoa(it->ClientAddr->sin_addr) << ":"
			<< ntohs(it->ClientAddr->sin_port) << endl;
	}
	it->iss.str(it->recData);//放入输入流
	it->iss.clear();//????
	cin.clear();
}