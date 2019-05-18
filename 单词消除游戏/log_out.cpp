#include"header.h"
#include"variable.h"
#include"function_declaration.h"

void log_out(string &username_player, string &username_test_maker)
{
	string name, type;
	cout << "请选择登出类型：闯关者player/出题者test_maker：\n";
	cin >> type;
	if (type == "player")  
	{
		/*检测是否登陆*/
		//if (it_user_player == v_player.end())
		if(username_player.empty())
		{
			cout << "请先登陆\n";
			return;
		}
		print_player(username_player);
		//it_user_player = v_player.end();
		username_player.resize(0);
		cout << "已登出" << endl;
	}
	else if (type == "test_maker")
	{
		/*检测是否登陆*/
		//if (it_user_test_maker == v_test_maker.end())//？？？？
		if(username_test_maker.empty())
		{
			cout << "请先登陆\n";
			return;
		}
		print_test_maker(username_test_maker);
		username_test_maker.resize(0);
		cout << "已登出" << endl;
		//it_user_test_maker = v_test_maker.end();
	}
	else
	{
		cout << "不正确的类型\n";
	}
	getchar();
}