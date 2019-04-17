#include"header.h"

/*全局变量*/
vector<player> v_player;//所有用户
vector<test_maker> v_test_maker;
vector<player>::iterator it_user_player;//当前系统用户
vector<test_maker>::iterator it_user_test_maker;
set<string> word_set;//单词集合

/*函数*/
void sign_up();
void log_in();
void log_out();
void add_word();
void start_game();

int main()
{
	//it_user_player == v_player.end();
	//it_user_test_maker == v_test_maker.end();
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
			if (it_user_test_maker == v_test_maker.end())
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
		/*查询：排名、排行榜等*/
		

		/**/
		else
			cout << "非法输入" << endl;
	}
	return 0;
}