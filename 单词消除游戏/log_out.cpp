#include"header.h"

/*ȫ�ֱ���*/
extern vector<player> v_player;
extern vector<test_maker> v_test_maker;
extern vector<player>::iterator it_user_player;
extern vector<test_maker>::iterator it_user_test_maker;
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