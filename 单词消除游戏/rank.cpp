#include"header.h"
#include"variable.h"
#include"function_declaration.h"



void rank_player(unsigned short int port)
{
	string choice;

	vector<sysInfo>::iterator it_sysInfo;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "��ѡ������ʽ��name/level/EXP/pass_count����\n";
	mySend(port);
	myRecv(port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->iss >> choice;
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
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�������\n";
		return;
	}
	//getchar();//�̻س�

	/*������а�*/
	int cnt = 0;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "����\t\t�û���\t\t�ȼ�\t\tEXP\t\tͨ����" << endl;
	for (auto val : v_player)
	{
		cnt++;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << cnt << "\t\t"
			<< val.show_name() << "\t\t" << val.show_level() << "\t\t"
			<< val.show_EXP() << "\t\t" << val.show_pass_count() << endl;
	}
	///*ȫ�ֱ�������������ָ���������û���ָ��*/
	//for (vector<player>::iterator it=v_player.begin();it!=v_player.end();it++)
	//{
	//	if (it->show_name() == username_player)
	//	{
	//		it_user_player = it;
	//		break;
	//	}
	//}
}

void rank_test_maker(unsigned short int port)
{
	string choice;
	vector<sysInfo>::iterator it_sysInfo;

	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "��ѡ������ʽ��name/level/EXP/pass_count����\n";
	mySend(port);
	myRecv(port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->iss >> choice;
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
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�������\n";
		return;
	}
	//getchar();//�̻س�

	/*������а�*/
	int cnt = 0;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "����\t\t�û���\t\t�ȼ�\t\tEXP\t\t������" << endl;
	for (auto val : v_test_maker)
	{
		cnt++;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << cnt << "\t\t"
			<< val.show_name() << "\t\t" << val.show_level() << "\t\t"
			<< val.show_EXP() << "\t\t" << val.show_word_num() << endl;
	}
	///*ȫ�ֱ�������������ָ���������û���ָ��*/
	//for (vector<test_maker>::iterator it = v_test_maker.begin(); it != v_test_maker.end(); it++)
	//{
	//	if (it->show_name() == username_test_maker)
	//	{
	//		it_user_test_maker = it;
	//		break;
	//	}
	//}
}

