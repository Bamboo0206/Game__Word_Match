/*�κν�ɫ���ɲ�ѯ���д����ߡ������ߣ��������Բ�����Ӧ�����ߡ������ߡ�*/
/*��ʾ�ý�ɫ��Ϣ*/

#include"header.h"
#include"variable.h"

void my_find(char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input = 0, string name_input = NULL);

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
		//the_one = find(v_player.begin(), v_player.end(), input_name);
		my_find('p', 'n', 0, input_name);
	}
	else if (choice == "level")
	{
		int level_input;
		cout << "������ȼ���" << endl;
		cin >> level_input;
		sort(v_player.begin(), v_player.end(), level_less());
		//the_one = find(v_player.begin(), v_player.end(), level_input);
		my_find('p', 'l', level_input);
	}
	else if (choice == "EXP")
	{
		long EXP_input;
		cout << "������EXP��" << endl;
		cin >> EXP_input;
		//the_one = find(v_player.begin(), v_player.end(), EXP_input);
		my_find('p', 'e', EXP_input);
	}
	else if (choice == "pass_count")
	{
		int pass_count_input;
		cout << "������ͨ������" << endl;
		cin >> pass_count_input;
		/*���� ���õȼ�����ȫ�����*/
		/*��������equal range����*/
		//the_one = find(v_player.begin(), v_player.end(), pass_count_input);
		my_find('p', 'p', pass_count_input);
	}
	else
	{
		cout << "�������\n";
		return;
	}

	/*���*/
	if (the_one == v_player.end())
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

/*�����Բ��ң�˳�����*/
void my_find(char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input , string name_input)
{
	int count = 0;
	cout << "�û���\t\t�ȼ�\t\tEXP\t\tͨ����" << endl;
	if (kind == 'p')//��player
	{
		switch (qaulity)
		{
		case 'n':
			for (auto val : v_player)
			{
				if (val.show_name() == name_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
					count++;
				}
			}
			break;
		case 'l':
			for (auto val : v_player)
			{
				if (val.show_level() == num_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
					count++;
				}
			}
			break;
		case 'e':
			for (auto val : v_player)
			{
				if (val.show_EXP() == num_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
					count++;
				}
			}
			break;
		case 'p':
			for (auto val : v_player)
			{
				if (val.show_pass_count() == (int)num_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
					count++;
				}
			}
			break;
		default:
			break;
		}
	}
	else if (kind == 't')//��test_maker
	{

	}
}