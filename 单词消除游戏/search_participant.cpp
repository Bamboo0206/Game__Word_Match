/*�κν�ɫ���ɲ�ѯ���д����ߡ������ߣ��������Բ�����Ӧ�����ߡ������ߡ�*/
/*��ʾ�ý�ɫ��Ϣ*/

#include"header.h"
#include"variable.h"

void search_player()
{
	/*��������*/
	vector<player>::iterator the_one/*Ҫ�ҵ���*/;
	string choice;

	cout << "��ѡ���ѯ�����ԣ�name/level/EXP/pass_count����" << endl;
	cin >> choice;
	if (choice == "name")
	{
		string input_name;
		cout << "�������û�����" << endl;
		cin >> input_name;
		the_one = find(v_player.begin(), v_player.end(), input_name);
	}
	else if (choice == "level")
	{
		int level_input;
		cout << "������ȼ���" << endl;
		cin >> level_input;
		/*���� ���õȼ�����ȫ�����*/
		/*��������equal range����*/
		sort(v_player.begin(), v_player.end(), level_less());
		//equal_range()//Ҫ��pair �� ������˵
		the_one = find(v_player.begin(), v_player.end(), level_input);
	}
	else if (choice == "EXP")
	{
		long EXP_input;
		cout << "������EXP��" << endl;
		cin >> EXP_input;
		/*���� ���õȼ�����ȫ�����*/
		/*��������equal range����*/
		the_one = find(v_player.begin(), v_player.end(), EXP_input);
	}
	else if (choice == "pass_count")
	{
		int pass_count_input;
		cout << "������ͨ������" << endl;
		cin >> pass_count_input;
		/*���� ���õȼ�����ȫ�����*/
		/*��������equal range����*/
		the_one = find(v_player.begin(), v_player.end(), pass_count_input);
	}
	else
	{
		cout << "�������\n";
		return;
	}

	/*���*/
	if (the_one == v_player.end)
	{
		cout << "not found" << endl;
	}
	else
	{
		cout << "�ҵ����û���\n"
			<< "�û�����" << the_one->show_name() << endl
			<< "�ȼ���" << the_one->show_level() << endl
			<< "EXP��" << the_one->show_EXP() << endl
			<< "ͨ������" << the_one->show_pass_count() << endl;
	}
}
void search_test_maker()
{

}