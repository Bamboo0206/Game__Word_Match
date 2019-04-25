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

		/*写文件*/
		fstream f_player("player.csv", ios::app);
		if (!f_player) { cerr << "无法打开文件player.csv" << endl; return; }
		f_player << p.show_name() << ','
			<< p.show_level() << ','
			<< p.show_EXP() << ','
			<< p.show_pass_count() << endl;

		cout << "注册成功！" << endl;
	}
	else if (type == "test_maker")
	{
		cout << "请输入用户名：\n";
		getline(cin, name);
		/*待改：输入正确性检验,检测重名*/

		test_maker t(name);
		v_test_maker.push_back(t);

		/*写文件*/
		fstream f_test_maker("test_maker.csv", ios::app);
		if (!f_test_maker) { cerr << "无法打开文件test_maker.csv" << endl; return; }
		f_test_maker << t.show_name() << ','
			<< t.show_level() << ','
			<< t.show_EXP() << ','
			<< t.show_word_num() << endl;

		cout << "注册成功！" << endl;
	}
	else
	{
		cout << "不正确的类型\n";
	}

}