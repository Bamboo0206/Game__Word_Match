#include"header.h"

/*ȫ�ֱ���*/
extern vector<player> v_player;
extern vector<test_maker> v_test_maker;
extern vector<player>::iterator it_user_player;
extern vector<test_maker>::iterator it_user_test_maker;

void log_in()
{
	string name, type;
	cout << "��ѡ���½���ͣ�������player/������test_maker��\n";
	cin >> type;
	cout << "�������û�����\n";
	getline(cin, name);
	/*���ģ�������ȷ�Լ���,�������*/
	//��ѡ��Ҫע������ͣ�������/������
	if (type == "player")
	{
		/*����find*/
		//player temp_player(name);
		//it_user_player = find(v_player.begin(), v_player.end(),temp_player);//����==��
		//find_if(, equal_name);
		vector<player>::iterator temp_it = v_player.begin();
		while (temp_it != v_player.end())
		{
			if ((*temp_it).show_name() == name)
			{
				it_user_player = temp_it;
				break;
			}
			else
			{
				temp_it++;
			}
		}
		if (it_user_player == v_player.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
		}
	}
	else if (type == "test_maker")
	{
		/*����find*/
		//test_maker temp_test_maker(name);
		//it_user_test_maker = find(v_test_maker.begin(), v_test_maker.end(), temp_test_maker);//����==��
		vector<test_maker>::iterator temp_it = v_test_maker.begin();
		while (temp_it != v_test_maker.end())
		{
			if (temp_it->show_name() == name)
			{
				it_user_test_maker = temp_it;
				break;
			}
			else
			{
				temp_it++;
			}
		}
		
		if (it_user_test_maker == v_test_maker.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
		}
	}
	else
	{
		cout << "����ȷ������\n";
	}
}

//find_participant()
//
//bool equal_name(participant &A, string &name)
//{
//	if (A.name == name)
//		return true;
//	else
//		return false;
//}