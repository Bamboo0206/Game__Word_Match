/*�κν�ɫ���ɲ�ѯ���д����ߡ������ߣ��������Բ�����Ӧ�����ߡ������ߡ�*/
/*��ʾ�ý�ɫ��Ϣ*/

#include"header.h"
#include"variable.h"
#include"function_declaration.h"

void my_find(unsigned short int port, char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input = 0, string name_input = "default");

void search_player(unsigned short int port)
{
	/*��������*/
	string choice;

	vector<sysInfo>::iterator it_sysInfo;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "��ѡ���ѯ�����ԣ�name/level/EXP/pass_count����" << endl;
	mySend(port);
	myRecv(port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->iss >> choice;
	if (choice == "name")
	{
		string input_name;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�������û�����" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> input_name;
		my_find(port,'p', 'n', 0, input_name);
	}
	else if (choice == "level")
	{
		int level_input;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "������ȼ���" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> level_input;
		my_find(port, 'p', 'l', level_input);
	}
	else if (choice == "EXP")
	{
		long EXP_input;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "������EXP��" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> EXP_input;
		my_find(port, 'p', 'e', EXP_input);
	}
	else if (choice == "pass_count")
	{
		int pass_count_input;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "������ͨ������" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> pass_count_input;
		my_find(port, 'p', 'p', pass_count_input);
	}
	else
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�������\n";
		return;
	}
}
void search_test_maker(unsigned short int port)
{
	/*��������*/
	string choice;
	vector<sysInfo>::iterator it_sysInfo;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "��ѡ���ѯ�����ԣ�name/level/EXP/word_num����" << endl;
	mySend(port);
	myRecv(port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->iss >> choice;

	if (choice == "name")
	{
		string input_name;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�������û�����" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> input_name;
		my_find(port,'t', 'n', 0, input_name);
	}
	else if (choice == "level")
	{
		int level_input;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "������ȼ���" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> level_input;
		my_find(port, 't', 'l', level_input);
	}
	else if (choice == "EXP")
	{
		long EXP_input;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "������EXP��" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> EXP_input;
		my_find(port, 't', 'e', EXP_input);
	}
	else if (choice == "word_num")
	{
		int word_num_input;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "������ͨ������" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> word_num_input;
		my_find(port,'t', 'w', word_num_input);
	}
	else
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�������\n";
		return;
	}
}

/*�����Բ��ң�˳�����ȫ��*/
void my_find( unsigned short int port,char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input , string name_input)
{
	vector<sysInfo>::iterator it_sysInfo;
	int count = 0;
	if (kind == 'p')//��player
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�û���\t\t�ȼ�\t\tEXP\t\tͨ����" << endl;
		switch (qaulity)
		{
		case 'n':
			for (auto val : v_player)
			{
				if (val.show_name() == name_input)
				{
					for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
					it_sysInfo->oss << val.show_name() << "\t\t" << val.show_level() << "\t\t"
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
					for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
					it_sysInfo->oss << val.show_name() << "\t\t" << val.show_level() << "\t\t"
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
					for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
					it_sysInfo->oss << val.show_name() << "\t\t" << val.show_level() << "\t\t"
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
					for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
					it_sysInfo->oss << val.show_name() << "\t\t" << val.show_level() << "\t\t"
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
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�û���\t\t�ȼ�\t\tEXP\t\tͨ����" << endl;
		switch (qaulity)
		{
		case 'n':
			for (auto val : v_test_maker)
			{
				if (val.show_name() == name_input)
				{
					for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
					it_sysInfo->oss << val.show_name() << "\t\t" << val.show_level() << "\t\t"
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
					for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
					it_sysInfo->oss << val.show_name() << "\t\t" << val.show_level() << "\t\t"
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
					for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
					it_sysInfo->oss << val.show_name() << "\t\t" << val.show_level() << "\t\t"
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
					for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
					it_sysInfo->oss << val.show_name() << "\t\t" << val.show_level() << "\t\t"
						<< val.show_EXP() << "\t\t" << val.show_word_num() << endl;
					count++;
				}
			}
			break;
		default:
			break;
		}
	}
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "������ϡ��ҵ�" << count << "����¼" << endl;
}