/*д������ģ�壿��*/

#include"header.h"
#include"variable.h"

/*ȫ�ֱ���*/
extern vector<player> v_player;//����player
extern vector<test_maker> v_test_maker;//����test_maker

void rank_player()
{
	string choice;

	cout << "��ѡ������ʽ��name/level/EXP/round����\n";
	cin >> choice;
	if (choice == "name")
	{
		sort(v_player.begin(), v_player.end(), name_less());
	}
	else if (choice == "level")
	{
		sort(v_player.begin(), v_player.end(), level_less());
	}
	else if (choice == "EXP")
	{
		sort(v_player.begin(), v_player.end(), EXP_less());
	}
	else if (choice == "round")
	{
		sort(v_player.begin(), v_player.end(), round_less());
	}
	else
	{
		cout << "�������\n";
		return;
	}

	/*������а�*/
	cout << "�û���\t\t�ȼ�\t\tEXP\t\tͨ����" << endl;
	for (auto val : v_player)
	{
		cout << val.show_name() << "\t\t" << val.show_level() << "\t\t" 
			<< val.show_EXP() << "\t\t" << val.show_round() << endl;
	}
}

void rank_test_maker()
{

}