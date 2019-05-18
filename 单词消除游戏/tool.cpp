#include"header.h"
#include"variable.h"

void locate_player(string name, vector<player>::iterator &it_user_player)//ʹ������ָ��name��player
{
	for (vector<player>::iterator it = v_player.begin(); it != v_player.end(); it++)
	{
		if (it->show_name() == name)
		{
			it_user_player = it;
			break;
		}
	}
}

void locate_test_maker(string name, vector<test_maker>::iterator &it_user_test_maker)
{
	for (vector<test_maker>::iterator it = v_test_maker.begin(); it != v_test_maker.end(); it++)
	{
		if (it->show_name() == name)
		{
			it_user_test_maker = it;
			break;
		}
	}
}

void print_player(string &username_player)
{
	vector<player>::iterator it_user_player;
	locate_player(username_player, it_user_player);
	cout << "name:" << it_user_player->show_name() << '\t'
		<< "level:" << it_user_player->show_level() << '\t'
		<< "EXP:" << it_user_player->show_EXP() << '\t'
		<< "ͨ����:" << it_user_player->show_pass_count() << endl;
}
void print_test_maker(string &username_test_maker)
{
	vector<test_maker>::iterator it_user_test_maker;
	cout << "name:" << it_user_test_maker->show_name() << '\t'
		<< "level:" << it_user_test_maker->show_level() << '\t'
		<< "EXP:" << it_user_test_maker->show_EXP() << '\t'
		<< "���뵥����:" << it_user_test_maker->show_word_num() << endl;
}


/*������ȷ�Լ��飬cin�������򷵻�true*/
bool cin_error_and_repair()
{
	if (!cin)
	{
		cerr << "input error!\n";
		cin.clear();
		cin.ignore(99999, '\n');//�����������з����������е���������
		return true;
	}
	else
		return false;
}