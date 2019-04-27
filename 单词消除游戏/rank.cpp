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
	cout << "用户名\t\t等级\t\tEXP\t\t通关数" << endl;
	for (auto val : v_player)
	{
		cout << val.show_name() << "\t\t" << val.show_level() << "\t\t" 
			<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
	}
}

void rank_test_maker()
{

}