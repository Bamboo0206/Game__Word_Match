/*任何角色均可查询所有闯关者、出题者，按照属性查找相应闯关者、出题者。*/
/*显示该角色信息*/

#include"header.h"
#include"variable.h"

void my_find(char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input = 0, string name_input = NULL);

void search_player()
{
	/*变量定义*/
	vector<player>::iterator the_one/*要找的人*/;
	string choice;

	cout << "请选择查询的属性（name/level/EXP/pass_count）：" << endl;
	cin >> choice;
	if (choice == "name")
	{
		string input_name;
		cout << "请输入用户名：" << endl;
		cin >> input_name;
		//the_one = find(v_player.begin(), v_player.end(), input_name);
		my_find('p', 'n', 0, input_name);
	}
	else if (choice == "level")
	{
		int level_input;
		cout << "请输入等级：" << endl;
		cin >> level_input;
		sort(v_player.begin(), v_player.end(), level_less());
		//the_one = find(v_player.begin(), v_player.end(), level_input);
		my_find('p', 'l', level_input);
	}
	else if (choice == "EXP")
	{
		long EXP_input;
		cout << "请输入EXP：" << endl;
		cin >> EXP_input;
		//the_one = find(v_player.begin(), v_player.end(), EXP_input);
		my_find('p', 'e', EXP_input);
	}
	else if (choice == "pass_count")
	{
		int pass_count_input;
		cout << "请输入通关数：" << endl;
		cin >> pass_count_input;
		/*待改 将该等级的人全部输出*/
		/*先排序再equal range？？*/
		//the_one = find(v_player.begin(), v_player.end(), pass_count_input);
		my_find('p', 'p', pass_count_input);
	}
	else
	{
		cout << "输入错误\n";
		return;
	}

	/*输出*/
	if (the_one == v_player.end())
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "找到该用户：\n"
			<< "用户名：" << the_one->show_name() << endl
			<< "等级：" << the_one->show_level() << endl
			<< "EXP：" << the_one->show_EXP() << endl
			<< "通关数：" << the_one->show_pass_count() << endl;
	}
}
void search_test_maker()
{

}

/*按属性查找，顺便输出*/
void my_find(char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input , string name_input)
{
	int count = 0;
	cout << "用户名\t\t等级\t\tEXP\t\t通关数" << endl;
	if (kind == 'p')//找player
	{
		switch (qaulity)
		{
		case 'n':
			for (auto val : v_player)
			{
				if (val.show_name() == name_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
					count++;
				}
			}
			break;
		case 'l':
			for (auto val : v_player)
			{
				if (val.show_level() == num_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
					count++;
				}
			}
			break;
		case 'e':
			for (auto val : v_player)
			{
				if (val.show_EXP() == num_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
					count++;
				}
			}
			break;
		case 'p':
			for (auto val : v_player)
			{
				if (val.show_pass_count() == (int)num_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
					count++;
				}
			}
			break;
		default:
			break;
		}
	}
	else if (kind == 't')//找test_maker
	{

	}
}