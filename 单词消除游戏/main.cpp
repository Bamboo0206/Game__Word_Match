#include"header.h"
#include"function_declaration.h"

/*全局变量*/
vector<player> v_player;//所有player
vector<test_maker> v_test_maker;//所有test_maker
vector<player>::iterator it_user_player;//当前系统用户
vector<test_maker>::iterator it_user_test_maker;
vector<string> word_set;//单词集合
//set<string,my_shorter> word_set;//单词集合//使用自定义my_shorter比较大小



int main()
{
	/*初始化 有问题*/
	//it_user_player == v_player.();
	//it_user_test_maker == v_test_maker.begin();
	srand((unsigned int) time(NULL));
	/*运行*/
	string option;
	while (true)
	{
		cout << "请选择操作：\n";
		getline(cin, option);
		/*注册*/
		if (option == "sign_up")
		{
			sign_up();
		}
		/*登陆*/
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
			/*检测是否登陆*/

			log_out();
		}
		/*查询：排名、排行榜等*/
		else if (option == "rank")
		{
			cout << "请选择要查看的排行榜（player/test_maker）：\n";
			string choice;
			cin >> choice;
			if (choice == "player")rank_player();
			else if (choice == "test_maker")rank_test_maker();
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
		else
			cout << "非法输入" << endl;
	}
	return 0;
}

