/*任何角色均可查询所有闯关者、出题者，按照属性查找相应闯关者、出题者。*/
/*显示该角色信息*/

#include"header.h"
#include"variable.h"

void search_player()
{
	/*变量定义*/
	vector<player>::iterator the_one/*要找的人*/;
	string choice;

	cout << "请选择查询的属性（name/level/EXP/round）：" << endl;
	cin >> choice;
	if (choice == "name")
	{
		string input_name;
		cout << "请输入用户名：" << endl;
		cin >> input_name;
		the_one = find(v_player.begin(), v_player.end(), input_name);
	}
	else if (choice == "level")
	{
		int level_input;
		cout << "请输入等级：" << endl;
		cin >> level_input;
		/*待改 将该等级的人全部输出*/
		/*先排序再equal range？？*/
		sort(v_player.begin(), v_player.end(), level_less());
		//equal_range()//要用pair 淦 改天再说
		the_one = find(v_player.begin(), v_player.end(), level_input);
	}
	else if (choice == "EXP")
	{
		long EXP_input;
		cout << "请输入EXP：" << endl;
		cin >> EXP_input;
		/*待改 将该等级的人全部输出*/
		/*先排序再equal range？？*/
		the_one = find(v_player.begin(), v_player.end(), EXP_input);
	}
	else if (choice == "round")
	{
		int round_input;
		cout << "请输入通关数：" << endl;
		cin >> round_input;
		/*待改 将该等级的人全部输出*/
		/*先排序再equal range？？*/
		the_one = find(v_player.begin(), v_player.end(), round_input);
	}
	else
	{
		cout << "输入错误\n";
		return;
	}

	/*输出*/
	if (the_one == v_player.end)
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "找到该用户：\n"
			<< "用户名：" << the_one->show_name() << endl
			<< "等级：" << the_one->show_level() << endl
			<< "EXP：" << the_one->show_EXP() << endl
			<< "通关数：" << the_one->show_round() << endl;
	}
}
void search_test_maker()
{

}