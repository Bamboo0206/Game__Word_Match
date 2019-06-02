#include"header.h"
#include"class.h"
#include"function_declaration.h"

/*全局变量*/
vector<player> v_player;//所有player
vector<test_maker> v_test_maker;//所有test_maker
vector<player>::iterator it_user_player;//当前系统用户
vector<test_maker>::iterator it_user_test_maker;
vector<string> word_set;//单词集合
string username_player, username_test_maker;//当前用户的用户名



int main()
{
	srand((unsigned int) time(NULL));
	read_wordlib();
	read_player();
	read_test_maker();
	it_user_player = v_player.end();
	it_user_test_maker = v_test_maker.end();

	/*运行*/
	string option;
	while (true)
	{
		cout<<"*****************************************\n"
			<<"注册：sign_up\n"
			<<"登陆：log_in\n"
			<<"闯关者：开始游戏：start_game\n"
			<<"出题者：新增单词：add_word\n"
			<<"排行榜：rank\n"
			<<"查找闯关者：search_player\n"
			<<"查找出题者：search_test_maker\n"
			<<"登出：log_out\n"
			<<"退出程序：quit\n"
			<<"*****************************************\n"
			<< "请选择操作：\n";
		getline(cin, option);
		/*注册*/
		if (option == "sign_up")
		{
			sign_up();
		}
		/*登陆*///如果已登陆的情况
		else if (option == "log_in")
		{
			log_in();
		}
		/*开始游戏*/
		else if (option == "start_game")
		{
			/*检测是否登陆*/
			if (it_user_player == v_player.end())
			{
				cout << "请先登陆\n";
			}
			else
			{
				start_game();
			}
		}
		/*新增单词*/
		else if (option == "add_word")
		{
			/*检测是否登陆*/
			if (it_user_test_maker == v_test_maker.end())//？？？？
			{
				cout << "请先登陆\n";
			}
			else
			{
				add_word();
			}
		}

		/*登出*/
		else if (option == "log_out")
		{
			log_out();
		}
		/*排行榜*/
		else if (option == "rank")
		{
			cout << "请选择要查看的排行榜（player/test_maker）：\n";
			string choice;
			cin >> choice;
			if (choice == "player")rank_player();
			else if (choice == "test_maker")rank_test_maker();
			else cout << "非法输入" << endl;
		}

		/*按角色属性查询*/
		else if (option == "search_player")
		{
			search_player();
		}
		else if (option == "search_test_maker")
		{
			search_test_maker();
		}

		/*退出系统 需要写文件*/
		else if (option == "quit")
		{
			write_participants();
			break;
		}
		else
			cout << "非法输入" << endl;
	}
	return 0;
}

