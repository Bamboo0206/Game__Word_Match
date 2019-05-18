#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*游戏每一关，程序会根据该关卡难度，显示一个单词，一定时间后单词消失。
闯关者需要在相应地方输入刚刚显示并消失的单词，如果闯关者输入正确则为通过。*/

void start_game(vector<player>::iterator &it_user_player)
{
	bool finish = false;
	string input_word;
	int difficulty = 1, size = 0;

	size = word_set.size();
	if (!size) { cout << "词库为空！请先添加单词\n"; return ; }

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		cout << "请选择难度（1-5）：" << endl;
		cin >> difficulty;
		if (!cin)//输入正确性检验
		{
			cerr << "input error!\n";
			cin.clear();
			cin.ignore(99999, '\n');//放弃包含换行符的输入流中的所有内容
			continue;
		}

		cout << "请记住这个单词（3s后消失）：" ;

		int loc = 0;//下标
		loc = rand() % (size / 5);
		switch (difficulty)
		{
		case 1://随机取前1/5单词
			break;
		case 2:
			loc += size * 1 / 5;
			break;
		case 3:
			loc += size * 2 / 5;
			break;
		case 4:
			loc += size * 3 / 5;
			break;
		case 5:
			loc += size * 4 / 5;
			break;
		default:
			cout << "非法输入" << endl;
			continue;//??
			break;
		}

		/*输出单词*/
		cout << word_set.at(loc);
		Sleep(3000);

		cout << "\r                                                            ";
		cout<<"\r请输入刚才出现的单词：";
		cin >> input_word;
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
			cout << "输入单词正确，闯关成功\n";
			/*更新等级、经验*/
			it_user_player->update_EXP(difficulty);
			it_user_player->update_level();
			it_user_player->inc_pass_count();
		}
		else//错误
		{
			cout << "输入单词错误，闯关失败\t刚才显示的单词是：" << word_set.at(loc) << endl;
		}

		cout << "请选择：继续游戏0/退出1（默认继续）\n";
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
	print_player(it_user_player);
	cout << "游戏已退出" << endl;
	return;
}

void print_player(vector<player>::iterator &it_user_player)
{
	cout <<"name:"<< it_user_player->show_name() << '\t'
		<< "level:" << it_user_player->show_level() << '\t'
		<< "EXP:" << it_user_player->show_EXP() << '\t'
		<< "通关数:" << it_user_player->show_pass_count() << endl;
}
void print_test_maker(vector<test_maker>::iterator &it_user_test_maker)
{
	cout << "name:" << it_user_test_maker->show_name() << '\t'
		<< "level:" << it_user_test_maker->show_level() << '\t'
		<< "EXP:" << it_user_test_maker->show_EXP() << '\t'
		<< "输入单词数:" << it_user_test_maker->show_word_num() << endl;
}