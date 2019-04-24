#include"header.h"
#include"variable.h"

void sign_up()
{
	string name, type;
	cout << "请选择注册类型：闯关者player/出题者test_maker：\n";
	cin >> type;
	getchar();//吞回车

	//请选择要注册的类型：闯关者/出题者
	if (type == "player")
	{
		cout << "请输入用户名：\n";
		getline(cin, name);
		/*待改：输入正确性检验,检测重名*/

		player p(name);
		v_player.push_back(p);
		cout << "注册成功！" << endl;
	}
	else if (type == "test_maker")
	{
		cout << "请输入用户名：\n";
		getline(cin, name);
		/*待改：输入正确性检验,检测重名*/

		test_maker t(name);
		v_test_maker.push_back(t);
		cout << "注册成功！" << endl;
	}
	else
	{
		cout << "不正确的类型\n";
	}

}