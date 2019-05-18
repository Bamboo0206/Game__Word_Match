#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*游戏每一关，程序会根据该关卡难度，显示一个单词，一定时间后单词消失。
闯关者需要在相应地方输入刚刚显示并消失的单词，如果闯关者输入正确则为通过。*/

bool one_round(string name);//一关，闯关成功返回true//传入pass_count+1

void start_game(string &username_player)
{
	bool finish = false;
	string input_word;
	int difficulty = 1, size = 0;

	size = word_set.size();
	if (!size) { cout << "词库为空！请先添加单词\n"; return ; }

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		if (one_round(username_player))//闯关成功
		{
			cout << "请选择：下一关0/退出1（默认继续）\n";
		}
		else//闯关失败
		{
			cout << "请选择：重新尝试该关0/退出1（默认继续）\n";
		}
		cin >> finish;
		if (!cin)//输入正确性检验
		{
			cerr << "input error!\n";
			cin.clear();
			cin.ignore(99999, '\n');//放弃包含换行符的输入流中的所有内容
			continue;
		}
	}
	/*输出用户信息*/
	print_player(username_player);
	cout << "游戏已退出" << endl;
	getchar();
	return;
}


bool one_round(string name)//一关，闯关成功返回true
{
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
	cout << "*********************************************************************\n"
		<< "                  第" << round_current << "关                  \n"
		<< "难度：" << difficulty << "级，单词：" << word_num_to_pass << "个，显示时间：" << display_time << "毫秒" << endl
		<< "您有" << error_chance << "次错误机会\n";

	string input_word;//用户输入的单词
	clock_t start = 0, finish = 0;//计时器
	double duration = 0;
	int loc = 0, wordlib_size = 0, word_passed = 0;//下标,单词数量,已通过数量
	wordlib_size = word_set.size();

	word_passed = 0;
	while (word_passed < word_num_to_pass && error_chance >= 0)
	{
		/*计算单词下标*/
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

		/*输出单词*/
		cout << "请记住这个单词（" << display_time << "毫秒后消失）："
			<< word_set.at(loc);
		Sleep(display_time);


		cout << "\r                                                            ";
		cout << "\r请输入刚才出现的单词：";
		/*待改：计时器*/
		start = clock();//启动计时器
		cin >> input_word;
		finish = clock();//关闭计时器
		duration += (double)(finish - start) / CLOCKS_PER_SEC;//算时间
		cout << "用时" << (double)(finish - start) / CLOCKS_PER_SEC << "秒" << endl;
		/*输入正确性检验*/
		if (!cin)
		{
			cerr << "input error!\n";
			cin.clear();
			cin.ignore(99999, '\n');//放弃包含换行符的输入流中的所有内容
			continue;
		}


		if (input_word == word_set.at(loc))//正确
		{
			cout << "输入单词正确\n";
			word_passed++;
		}
		else//错误
		{
			cout << "输入单词错误\t刚才显示的单词是：" << word_set.at(loc) << endl;
			Sleep(2000);
			if (--error_chance == -1)
			{
				break;
			}
			cout << "您还有" << error_chance << "次错误机会" << endl;
		}
	}
	/*更新等级、经验*/
	if (word_passed == word_num_to_pass)
	{
		cout << "闯关成功\n";
		it_user_player->inc_pass_count();
		it_user_player->update_EXP(duration, round_current);
		it_user_player->update_level();
		return true;
	}
	else
	{
		cout << "闯关失败" << endl;
		return false;
	}

}
