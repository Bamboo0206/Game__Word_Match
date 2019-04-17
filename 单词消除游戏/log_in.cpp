#include"header.h"

/*全局变量*/
extern vector<player> v_player;
extern vector<test_maker> v_test_maker;
extern vector<player>::iterator it_user_player;
extern vector<test_maker>::iterator it_user_test_maker;

void log_in()
{
	string name, type;
	cout << "请选择登陆类型：闯关者player/出题者test_maker：\n";
	cin >> type;
	cout << "请输入用户名：\n";
	getline(cin, name);
	/*待改：输入正确性检验,检测重名*/
	//请选择要注册的类型：闯关者/出题者
	if (type == "player")
	{
		/*待改find*/
		//player temp_player(name);
		//it_user_player = find(v_player.begin(), v_player.end(),temp_player);//重载==？
		//find_if(, equal_name);
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
		if (it_user_player == v_player.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
		}
	}
	else if (type == "test_maker")
	{
		/*待改find*/
		//test_maker temp_test_maker(name);
		//it_user_test_maker = find(v_test_maker.begin(), v_test_maker.end(), temp_test_maker);//重载==？
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
		
		if (it_user_test_maker == v_test_maker.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
		}
	}
	else
	{
		cout << "不正确的类型\n";
	}
}

//find_participant()
//
//bool equal_name(participant &A, string &name)
//{
//	if (A.name == name)
//		return true;
//	else
//		return false;
//}