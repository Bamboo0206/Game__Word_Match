#include"header.h"
#include"variable.h"
#include"function_declaration.h"

void log_out()
{
	string name, type;
	cout << "��ѡ��ǳ����ͣ�������player/������test_maker��\n";
	cin >> type;
	if (type == "player")  
	{/*����Ƿ��½*/
		if (it_user_player == v_player.end())
		{
			cout << "���ȵ�½\n";
			return;
		}
		print_player();
		cout << "�ѵǳ�" << endl;
		it_user_player = v_player.end();
	}
	else if (type == "test_maker")
	{
		/*����Ƿ��½*/
		if (it_user_test_maker == v_test_maker.end())//��������
		{
			cout << "���ȵ�½\n";
			return;
		}
		print_test_maker();
		cout << "�ѵǳ�" << endl;
		it_user_test_maker = v_test_maker.end();
	}
	else
	{
		cout << "����ȷ������\n";
	}
	getchar();
}