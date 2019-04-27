/*写个函数模板？？*/

#include"header.h"
#include"variable.h"

/*全局变量*/

void rank_player()
{
	string choice;

	cout << "请选择排序方式（name/level/EXP/pass_count）：\n";
	cin >> choice;
	if (choice == "name")
	{
		sort(v_player.begin(), v_player.end(), name_greater());
	}
	else if (choice == "level")
	{
		sort(v_player.begin(), v_player.end(), level_greater());
	}
	else if (choice == "EXP")
	{
		sort(v_player.begin(), v_player.end(), EXP_greater());
	}
	else if (choice == "pass_count")
	{
		sort(v_player.begin(), v_player.end(), pass_count_greater());
	}
	else
	{
		cout << "输入错误\n";
		return;
	}
	getchar();//吞回车

	/*输出排行榜*/
	int cnt = 0;
	cout << "名次\t\t用户名\t\t等级\t\tEXP\t\t通关数" << endl;
	for (auto val : v_player)
	{
		cnt++;
		cout << cnt << "\t\t"
			<< val.show_name() << "\t\t" << val.show_level() << "\t\t"
			<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
	}
}

void rank_test_maker()
{
	string choice;

	cout << "请选择排序方式（name/level/EXP/pass_count）：\n";
	cin >> choice;
	if (choice == "name")
	{
		sort(v_test_maker.begin(), v_test_maker.end(), name_greater());
	}
	else if (choice == "level")
	{
		sort(v_test_maker.begin(), v_test_maker.end(), level_greater());
	}
	else if (choice == "EXP")
	{
		sort(v_test_maker.begin(), v_test_maker.end(), EXP_greater());
	}
	else if (choice == "word_num")
	{
		sort(v_test_maker.begin(), v_test_maker.end(), word_num_greater());
	}
	else
	{
		cout << "输入错误\n";
		return;
	}
	getchar();//吞回车

	/*输出排行榜*/
	int cnt = 0;
	cout << "名次\t\t用户名\t\t等级\t\tEXP\t\t通关数" << endl;
	for (auto val : v_test_maker)
	{
		cnt++;
		cout << cnt << "\t\t"
			<< val.show_name() << "\t\t" << val.show_level() << "\t\t"
			<< val.show_EXP() << "\t\t" << val.show_word_num() << endl;
	}
}

/*通用函数*/

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