/*�κν�ɫ���ɲ�ѯ���д����ߡ������ߣ��������Բ�����Ӧ�����ߡ������ߡ�*/
/*��ʾ�ý�ɫ��Ϣ*/

#include"header.h"
#include"variable.h"
#include"function_declaration.h"

void my_find(char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input = 0, string name_input = "default");

void search_player(unsigned short int port)
{
	/*��������*/
	string choice;

	cout << "��ѡ���ѯ�����ԣ�name/level/EXP/pass_count����" << endl;
	mySend(port);
	myRecv(port);
	cin >> choice;
	if (choice == "name")
	{
		string input_name;
		cout << "�������û�����" << endl;
		mySend(port);
		myRecv(port);
		cin >> input_name;
		if (cin_error_and_repair())//��ȷ�Լ���
		{
			cout << "�����������û�����" << endl;
			mySend(port);
			myRecv(port);
			cin >> input_name;
		}
		my_find('p', 'n', 0, input_name);
	}
	else if (choice == "level")
	{
		int level_input;
		cout << "������ȼ���" << endl;
		mySend(port);
		myRecv(port);
		cin >> level_input;
		if (cin_error_and_repair())
		{
			cout << "����������ȼ���" << endl;
			mySend(port);
			myRecv(port);
			cin >> level_input;
		}
		my_find('p', 'l', level_input);
	}
	else if (choice == "EXP")
	{
		long EXP_input;
		cout << "������EXP��" << endl;
		mySend(port);
		myRecv(port);
		cin >> EXP_input;
		if (cin_error_and_repair())
		{
			cout << "����������EXP��" << endl;
			mySend(port);
			myRecv(port);
			cin >> EXP_input;
		}
		my_find('p', 'e', EXP_input);
	}
	else if (choice == "pass_count")
	{
		int pass_count_input;
		cout << "������ͨ������" << endl;
		mySend(port);
		myRecv(port);
		cin >> pass_count_input;
		if (cin_error_and_repair())
		{
			cout << "����������ͨ������" << endl;
			mySend(port);
			myRecv(port);
			cin >> pass_count_input;
		}
		my_find('p', 'p', pass_count_input);
	}
	else
	{
		cout << "�������\n";
		return;
	}
	//getchar();//�̻س�
}
void search_test_maker(unsigned short int port)
{
	/*��������*/
	string choice;

	cout << "��ѡ���ѯ�����ԣ�name/level/EXP/word_num����" << endl;
	mySend(port);
	myRecv(port);
	cin >> choice;

	if (choice == "name")
	{
		string input_name;
		cout << "�������û�����" << endl;
		mySend(port);
		myRecv(port);
		cin >> input_name;
		if (cin_error_and_repair())//��ȷ�Լ���
		{
			cout << "�����������û�����" << endl;
			mySend(port);
			myRecv(port);
			cin >> input_name;
		}
		my_find('t', 'n', 0, input_name);
	}
	else if (choice == "level")
	{
		int level_input;
		cout << "������ȼ���" << endl;
		mySend(port);
		myRecv(port);
		cin >> level_input;
		if (cin_error_and_repair())//��ȷ�Լ���
		{
			cout << "����������ȼ���" << endl;
			mySend(port);
			myRecv(port);
			cin >> level_input;
		}
		my_find('t', 'l', level_input);
	}
	else if (choice == "EXP")
	{
		long EXP_input;
		cout << "������EXP��" << endl;
		mySend(port);
		myRecv(port);
		cin >> EXP_input;
		if (cin_error_and_repair())//��ȷ�Լ���
		{
			cout << "����������EXP��" << endl;
			mySend(port);
			myRecv(port);
			cin >> EXP_input;
		}
		my_find('t', 'e', EXP_input);
	}
	else if (choice == "word_num")
	{
		int word_num_input;
		cout << "������ͨ������" << endl;
		mySend(port);
		myRecv(port);
		cin >> word_num_input;
		if (cin_error_and_repair())//��ȷ�Լ���
		{
			cout << "����������ͨ������" << endl;
			mySend(port);
			myRecv(port);
			cin >> word_num_input;
		}
		my_find('t', 'w', word_num_input);
	}
	else
	{
		cout << "�������\n";
		return;
	}
	//getchar();//�̻س�
}

/*�����Բ��ң�˳�����ȫ��*/
void my_find(char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input , string name_input)
{
	int count = 0;
	if (kind == 'p')//��player
	{
		cout << "�û���\t\t�ȼ�\t\tEXP\t\tͨ����" << endl;
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
		cout << "�û���\t\t�ȼ�\t\tEXP\t\tͨ����" << endl;
		switch (qaulity)
		{
		case 'n':
			for (auto val : v_test_maker)
			{
				if (val.show_name() == name_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_word_num() << endl;
					count++;
				}
			}
			break;
		case 'l':
			for (auto val : v_test_maker)
			{
				if (val.show_level() == num_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_word_num() << endl;
					count++;
				}
			}
			break;
		case 'e':
			for (auto val : v_test_maker)
			{
				if (val.show_EXP() == num_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_word_num() << endl;
					count++;
				}
			}
			break;
		case 'w':
			for (auto val : v_test_maker)
			{
				if (val.show_word_num() == (int)num_input)
				{
					cout << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_word_num() << endl;
					count++;
				}
			}
			break;
		default:
			break;
		}
	}
	cout << "������ϡ��ҵ�" << count << "����¼" << endl;
}