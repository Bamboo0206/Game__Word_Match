#include"header.h"

/*ȫ�ֱ���*/
extern vector<player> v_player;
extern vector<test_maker> v_test_maker;
void sign_up()
{
	string name, type;
	cout << "��ѡ��ע�����ͣ�������player/������test_maker��\n";
	cin >> type;
	getchar();//�̻س�

	//��ѡ��Ҫע������ͣ�������/������
	if (type == "player")
	{
		cout << "�������û�����\n";
		getline(cin, name);
		/*���ģ�������ȷ�Լ���,�������*/

		player p(name);
		v_player.push_back(p);
		cout << "ע��ɹ���" << endl;
	}
	else if (type == "test_maker")
	{
		cout << "�������û�����\n";
		getline(cin, name);
		/*���ģ�������ȷ�Լ���,�������*/

		test_maker t(name);
		v_test_maker.push_back(t);
		cout << "ע��ɹ���" << endl;
	}
	else
	{
		cout << "����ȷ������\n";
	}

}