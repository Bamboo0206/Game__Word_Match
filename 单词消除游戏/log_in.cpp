#include"header.h"
#include"variable.h"
#include"function_declaration.h"


void log_in(vector<player>::iterator &it_user_player,vector<test_maker>::iterator &it_user_test_maker)
{
	string name, type;
	cout << "��ѡ���½���ͣ�������player/������test_maker��\n";
	cin >> type;
	getchar();//�̻س�
	cout << "�������û�����\n";
	getline(cin, name);
	//��ѡ��Ҫע������ͣ�������/������
	if (type == "player")
	{
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
		if (temp_it == v_player.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
			print_player(it_user_player);
			username_player = it_user_player->show_name();
		}
	}
	else if (type == "test_maker")
	{
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
		
		if (temp_it == v_test_maker.end())
		{
			cout << "not found\n";
		}
		else
		{
			cout << "log in successfully\n";
			print_test_maker(it_user_test_maker);
			username_test_maker = it_user_test_maker->show_name();
		}
	}
	else
	{
		cout << "����ȷ������\n";
	}
}
