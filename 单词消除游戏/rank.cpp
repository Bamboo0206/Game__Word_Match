/*д������ģ�壿��*/

#include"header.h"
#include"variable.h"

/*ȫ�ֱ���*/

void rank_player()
{
	string choice;

	cout << "��ѡ������ʽ��name/level/EXP/pass_count����\n";
	cin >> choice;
	if (choice == "name")
	{
		sort(v_player.begin(), v_player.end(), name_greater());
	}
	else if (choice == "level")
	{
		sort(v_player.begin(), v_player.end(), level_greater());
	}
	else if (choice == "EXP")
	{
		sort(v_player.begin(), v_player.end(), EXP_greater());
	}
	else if (choice == "pass_count")
	{
		sort(v_player.begin(), v_player.end(), pass_count_greater());
	}
	else
	{
		cout << "�������\n";
		return;
	}
	getchar();//�̻س�

	/*������а�*/
	int cnt = 0;
	cout << "����\t\t�û���\t\t�ȼ�\t\tEXP\t\tͨ����" << endl;
	for (auto val : v_player)
	{
		cnt++;
		cout << cnt << "\t\t"
			<< val.show_name() << "\t\t" << val.show_level() << "\t\t"
			<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
	}
}

void rank_test_maker()
{
	string choice;

	cout << "��ѡ������ʽ��name/level/EXP/pass_count����\n";
	cin >> choice;
	if (choice == "name")
	{
		sort(v_test_maker.begin(), v_test_maker.end(), name_greater());
	}
	else if (choice == "level")
	{
		sort(v_test_maker.begin(), v_test_maker.end(), level_greater());
	}
	else if (choice == "EXP")
	{
		sort(v_test_maker.begin(), v_test_maker.end(), EXP_greater());
	}
	else if (choice == "word_num")
	{
		sort(v_test_maker.begin(), v_test_maker.end(), word_num_greater());
	}
	else
	{
		cout << "�������\n";
		return;
	}
	getchar();//�̻س�

	/*������а�*/
	int cnt = 0;
	cout << "����\t\t�û���\t\t�ȼ�\t\tEXP\t\tͨ����" << endl;
	for (auto val : v_test_maker)
	{
		cnt++;
		cout << cnt << "\t\t"
			<< val.show_name() << "\t\t" << val.show_level() << "\t\t"
			<< val.show_EXP() << "\t\t" << val.show_word_num() << endl;
	}
}

/*ͨ�ú���*/

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