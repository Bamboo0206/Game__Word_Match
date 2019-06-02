#include"header.h"
#include"variable.h"

//使迭代器指向name的player
void locate_player(string name, vector<player>::iterator &it_user_player)
{
	for (vector<player>::iterator it = v_player.begin(); it != v_player.end(); it++)
	{
		if (it->show_name() == name)
		{
			it_user_player = it;
			return;
		}
	}
	it_user_player = v_player.end();
}

void locate_test_maker(string name, vector<test_maker>::iterator& it_user_test_maker)
{
	for (vector<test_maker>::iterator it = v_test_maker.begin(); it != v_test_maker.end(); it++)
	{
		if ((*it).show_name() == name)
		{
			it_user_test_maker = it;
			return;
		}
	}
	it_user_test_maker = v_test_maker.end();
}

/*打印用户信息*/
void print_player(string &username_player, unsigned short int port)
{
	vector<player>::iterator it_user_player;
	locate_player(username_player, it_user_player);
	vector<sysInfo>::iterator it_sysInfo;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	if (it_sysInfo == v_sysInfo.end()) {cerr << "iterator out of range\n";return;}
	it_sysInfo->oss << "name:" << it_user_player->show_name() << '\t'
		<< "level:" << it_user_player->show_level() << '\t'
		<< "EXP:" << it_user_player->show_EXP() << '\t'
		<< "通关数:" << it_user_player->show_pass_count() << endl;
}
void print_test_maker(string &username_test_maker,  unsigned short int port)
{
	vector<test_maker>::iterator it_user_test_maker;
	locate_test_maker(username_test_maker, it_user_test_maker);
	vector<sysInfo>::iterator it_sysInfo;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "name:" << it_user_test_maker->show_name() << '\t'
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


/*通过将cin和cout重定向到stringstream，从stringstream中读取内容发送*/
void mySend(unsigned short int port)
{
	vector<sysInfo>::iterator it;
	for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->ClientAddr->sin_port != port; it++);//通过port找到该全局变量
	it->oss.getline(it->sendData, BUF_SIZE, '\0');//将oss流里的数据拷贝到sendData数组里，以\0结尾
	send(*(it->sClient), it->sendData, strlen(it->sendData), 0);//发送数据
	it->oss.str("");//清空流
	it->oss.clear();
}
void myRecv(unsigned short int port)
{

	vector<sysInfo>::iterator it;
	for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->ClientAddr->sin_port != port; it++);//通过port找到该全局变量
	
	int ret = recv(*(it->sClient), it->recData, BUF_SIZE, 0);
	for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->ClientAddr->sin_port != port; it++);
	if (ret > 0)
	{
		it->recData[ret] = '\0';
		if (DEBUG) cerr << it->recData << endl;

	}
	else if (ret == 0)/*关闭*/
	{
		cerr << "Disconected:" << inet_ntoa(it->ClientAddr->sin_addr) << ":"
			<< ntohs(it->ClientAddr->sin_port) << endl;
		shutdown(*(it->sClient), SD_SEND);
		closesocket(*(it->sClient));//正常关闭会返回0
	}
	else if (ret < 0)/*不正常关闭*/
	{
		cerr << "Disconected:" << inet_ntoa(it->ClientAddr->sin_addr) << ":"
			<< ntohs(it->ClientAddr->sin_port) << endl;
	}
	it->iss.str(it->recData);//放入输入流
	it->iss.clear();
}