#include"header.h"

/*全局变量*/
extern vector<player> v_player;
extern vector<test_maker> v_test_maker;
extern vector<player>::iterator it_user_player;
extern vector<test_maker>::iterator it_user_test_maker;
void log_out()
{
	string name, type;
	cout << "请选择登出类型：闯关者player/出题者test_maker：\n";
	cin >> type;
	if (type == "player")  
	{
		it_user_player = v_player.end();
	}
	else if (type == "test_maker")
	{
		it_user_test_maker = v_test_maker.end();
	}
	else
	{
		cout << "不正确的类型\n";
	}
}