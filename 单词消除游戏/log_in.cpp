#include"header.h"
#include"variable.h"
#include"function_declaration.h"


void log_in()
{
	string name, type;
	cout << "请选择登陆类型：闯关者player/出题者test_maker：\n";
	cin >> type;
	getchar();//吞回车
	cout << "请输入用户名：\n";
	getline(cin, name);
	//请选择要注册的类型：闯关者/出题者
	if (type == "player")
	{
		vector<player>::iterator temp_it = v_player.begin();
		while (temp_it != v_player.end())
		{
			if ((*temp_it).show_name() == name)
			{
				it_user_player = temp_it;
				break;
			}
			else
			{
				temp_it++;
			}
		}
		if (temp_it == v_player.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
			print_player();
		}
	}
	else if (type == "test_maker")
	{
		vector<test_maker>::iterator temp_it = v_test_maker.begin();
		while (temp_it != v_test_maker.end())
		{
			if (temp_it->show_name() == name)
			{
				it_user_test_maker = temp_it;
				break;
			}
			else
			{
				temp_it++;
			}
		}
		
		if (temp_it == v_test_maker.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
			print_test_maker();
		}
	}
	else
	{
		cout << "不正确的类型\n";
	}
}
