#include"header.h"

/*全局变量*/
extern vector<player> v_player;
extern vector<test_maker> v_test_maker;
void sign_up()
{
	string name, type;
	cout << "请选择注册类型：闯关者player/出题者test_maker：\n";
	cin >> type;
	cout << "请输入用户名：\n";
	getline(cin, name);
	/*待改：输入正确性检验,检测重名*/
	//请选择要注册的类型：闯关者/出题者
	if (type == "player")
	{
		player p(name);
		v_player.push_back(p);
	}
	else if (type == "test_maker")
	{
		test_maker t(name);
		v_test_maker.push_back(t);
	}
	else
	{
		cout << "不正确的类型\n";
	}

}