#include"header.h"
#include"variable.h"

void log_out()
{
	string name, type;
	cout << "��ѡ��ǳ����ͣ�������player/������test_maker��\n";
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
		cout << "����ȷ������\n";
	}
}