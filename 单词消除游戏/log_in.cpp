#include"header.h"
#include"variable.h"
#include"function_declaration.h"


void log_in(string &username_player,string &username_test_maker ,unsigned short int port)
{
	string name, type;
	vector<sysInfo>::iterator it_sysInfo;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "��ѡ���½���ͣ�������player/������test_maker��\n";
	mySend(port);

	myRecv(port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->iss >> type;
	//getchar();//�̻س�
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "�������û�����\n";
	mySend(port);
	myRecv(port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->iss >> name;
	//getline(cin, name);
	
	if (type == "player")
	{
		//vector<sysInfo>::iterator it;
		//for (it = v_sysInfo.begin(); it != v_sysInfo.end() && it->sClient != ; it++);//��λ��
		//it->kind = 0;
		vector<player>::iterator temp_it/* = v_player.begin()*/;
		locate_player(name, temp_it);
		if (temp_it == v_player.end())
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "not found\n";
		}
		else
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "log in successfully\n";
			it_sysInfo->kind = 0;//дϵͳ��Ϣ
			it_sysInfo->name = name;
			username_player = name;

			print_player(name,port);
		}
	}
	else if (type == "test_maker")
	{
		vector<test_maker>::iterator temp_it /*= v_test_maker.begin()*/;
		locate_test_maker(name, temp_it);
		if (temp_it == v_test_maker.end())
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "not found\n";
		}
		else
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "log in successfully\n";
			it_sysInfo->kind = 1;//дϵͳ��Ϣ
			it_sysInfo->name = name;
			print_test_maker(name, port);
			username_test_maker = name;
		}
	}
	else
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "����ȷ������\n";
	}
}
