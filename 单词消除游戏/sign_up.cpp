#include"header.h"
#include"variable.h"

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

		/*д�ļ�*/
		fstream f_player("player.csv", ios::app);
		if (!f_player) { cerr << "�޷����ļ�player.csv" << endl; return; }
		f_player << p.show_name() << ','
			<< p.show_level() << ','
			<< p.show_EXP() << ','
			<< p.show_pass_count() << endl;

		cout << "ע��ɹ���" << endl;
	}
	else if (type == "test_maker")
	{
		cout << "�������û�����\n";
		getline(cin, name);
		/*���ģ�������ȷ�Լ���,�������*/

		test_maker t(name);
		v_test_maker.push_back(t);

		/*д�ļ�*/
		fstream f_test_maker("test_maker.csv", ios::app);
		if (!f_test_maker) { cerr << "�޷����ļ�test_maker.csv" << endl; return; }
		f_test_maker << t.show_name() << ','
			<< t.show_level() << ','
			<< t.show_EXP() << ','
			<< t.show_word_num() << endl;

		cout << "ע��ɹ���" << endl;
	}
	else
	{
		cout << "����ȷ������\n";
	}

}