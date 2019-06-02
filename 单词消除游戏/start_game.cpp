#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*游戏每一关，程序会根据该关卡难度，显示一个单词，一定时间后单词消失。
闯关者需要在相应地方输入刚刚显示并消失的单词，如果闯关者输入正确则为通过。*/

bool one_round(string name, unsigned short int port);//一关，闯关成功返回true//传入pass_count+1

void start_game(string &username_player, unsigned short int port)
{
	bool finish = false;
	string input_word;
	int difficulty = 1, size = 0;
	vector<sysInfo>::iterator it_sysInfo;
	size = word_set.size();
	if (!size) 
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "词库为空！请先添加单词\n";
		return;
	}

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		if (one_round(username_player,port))//闯关成功
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "请选择：下一关0/退出1（默认继续）\n";
		}
		else//闯关失败
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "请选择：重新尝试该关0/退出1（默认继续）\n";
		}
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> finish;
	}
	/*输出用户信息*/
	print_player(username_player, port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "游戏已退出" << endl;
	//getchar();
	return;
}


bool one_round(string name, unsigned short int port)//一关，闯关成功返回true
{
	vector<sysInfo>::iterator it_sysInfo;
	vector<player>::iterator it_user_player;
	locate_player(name, it_user_player);
	int round_current = it_user_player->show_pass_count() + 1;

	/*计算单词长度（5级），单词个数，显示时间*/
	int difficulty = 1, word_num_to_pass = 0, display_time = 0, error_chance = 0;
	difficulty = round_current / 3;
	difficulty = difficulty < 5 ? difficulty : 5;//上限5级
	word_num_to_pass = sqrt(round_current);
	display_time = -round_current * 2000 / 15 + 3000;
	display_time = display_time > 1000 ? display_time : 1000;//下限1000
	error_chance = -round_current * 2 / 15 + 3;
	error_chance = error_chance > 1 ? error_chance : 1;//下限1
		/*输出*/
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "*********************************************************************\n"
		<< "                  第" << round_current << "关                  \n"
		<< "难度：" << difficulty << "级，单词：" << word_num_to_pass << "个，显示时间：" << display_time << "毫秒" << endl
		<< "您有" << error_chance << "次错误机会\n";
	mySend(port);
	double duration = 0;
	int loc = 0, wordlib_size = 0, word_passed = 0;//下标,单词数量,已通过数量
	wordlib_size = word_set.size();
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << word_num_to_pass << " " << error_chance << "\n\0";
	mySend(port);
	Sleep(50);

	word_passed = 0;
	while (word_passed < word_num_to_pass && error_chance >= 0)
	{
		/*将单词难度分为5级，根据难度在区间内随机取单词*/
		loc = rand() % (wordlib_size / 5);
		switch (difficulty)
		{
		case 1://随机取前1/5单词
			break;
		case 2:
			loc += wordlib_size * 1 / 5;
			break;
		case 3:
			loc += wordlib_size * 2 / 5;
			break;
		case 4:
			loc += wordlib_size * 3 / 5;
			break;
		case 5:
			loc += wordlib_size * 4 / 5;
			break;
		default:
			break;
		}

		/*服务器发送单词和该单词显示的时间，客户端发回用户是否答对和答题耗时*/
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << display_time << "\n"<< word_set.at(loc);
		mySend(port);

		/*接收结果*/
		myRecv(port);
		char result;//结果
		double tempD;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> result >> tempD;

		duration += tempD;//算时间;
		

		if (result=='1')//正确
		{
			word_passed++;
		}
		else//错误
		{
			if (--error_chance == -1)
			{
				break;
			}
		}
	}
	/*更新等级、经验*/
	if (word_passed == word_num_to_pass)
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "闯关成功\n";

		vector<player>::iterator it_user_player;
		locate_player(name, it_user_player);

		it_sysInfo->oss << "EXP+" << it_user_player->update_EXP(duration, round_current) << endl;
		locate_player(name, it_user_player);
		it_user_player->inc_pass_count();
		it_user_player->update_level();
		return true;
	}
	else
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "闯关失败" << endl;
		return false;
	}

}
