#include"header.h"
#include"variable.h"
#include"function_declaration.h"


void log_in(string &username_player,string &username_test_maker)
{
	string name, type;
	cout << "请选择登陆类型：闯关者player/出题者test_maker：\n";

	cin >> type;
	getchar();//吞回车
	cout << "请输入用户名：\n";
	getline(cin, name);
	
	if (type == "player")
	{
		//vector<sysInfo>::iterator it;
		//for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->sClient != ; it++);//定位到
		//it->kind = 0;
		vector<player>::iterator temp_it/* = v_player.begin()*/;
		locate_player(name, temp_it);
		if (temp_it == v_player.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
			username_player = name;
			//it->name = name;//写系统信息
			print_player(name);
		}
	}
	else if (type == "test_maker")
	{
		vector<test_maker>::iterator temp_it /*= v_test_maker.begin()*/;
		locate_test_maker(name, temp_it);
		if (temp_it == v_test_maker.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
			print_test_maker(name);
			username_test_maker = name;
		}
	}
	else
	{
		cout << "不正确的类型\n";
	}
}
