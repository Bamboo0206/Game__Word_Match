#include"header.h"
#include"variable.h"
#include"function_declaration.h"

void log_out(string &username_player, string &username_test_maker)
{
	string name, type;
	cout << "��ѡ��ǳ����ͣ�������player/������test_maker��\n";
	cin >> type;
	if (type == "player")  
	{
		/*����Ƿ��½*/
		//if (it_user_player == v_player.end())
		if(username_player.empty())
		{
			cout << "���ȵ�½\n";
			return;
		}
		print_player(username_player);
		//it_user_player = v_player.end();
		username_player.resize(0);
		cout << "�ѵǳ�" << endl;
	}
	else if (type == "test_maker")
	{
		/*����Ƿ��½*/
		//if (it_user_test_maker == v_test_maker.end())//��������
		if(username_test_maker.empty())
		{
			cout << "���ȵ�½\n";
			return;
		}
		print_test_maker(username_test_maker);
		username_test_maker.resize(0);
		cout << "�ѵǳ�" << endl;
		//it_user_test_maker = v_test_maker.end();
	}
	else
	{
		cout << "����ȷ������\n";
	}
	getchar();
}