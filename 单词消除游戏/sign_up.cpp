#include"header.h"

/*ȫ�ֱ���*/
extern vector<player> v_player;
extern vector<test_maker> v_test_maker;
void sign_up()
{
	string name, type;
	cout << "��ѡ��ע�����ͣ�������player/������test_maker��\n";
	cin >> type;
	cout << "�������û�����\n";
	getline(cin, name);
	/*���ģ�������ȷ�Լ���,�������*/
	//��ѡ��Ҫע������ͣ�������/������
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
		cout << "����ȷ������\n";
	}

}