#include"header.h"
#include"variable.h"
#include"function_declaration.h"

void sign_up(unsigned short int port)
{
	vector<sysInfo>::iterator it_sysInfo;
	string name, type;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "��ѡ��ע�����ͣ�������player/������test_maker��\n\0";
	mySend(port);
	myRecv(port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->iss >> type;
	//getchar();//�̻س�

	//��ѡ��Ҫע������ͣ�������/������
	if (type == "player")
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�������û�����\n";
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> name;
		//getline(cin, name);
		/*�������*/
		bool user_exist = false;
		for (auto val : v_player)
		{
			if (val.show_name() == name)
			{
				user_exist = true;
			}
		}
		if (user_exist)
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "���û����Ѵ��ڣ���ֱ�ӵ�½" << endl;
			return;
		}

		player p(name);
		v_player.push_back(p);

		/*д�ļ�*/
		fstream f_player("player.csv", ios::app);
		if (!f_player) { cerr << "�޷����ļ�player.csv" << endl; return; }
		f_player << p.show_name() << ','
			<< p.show_level() << ','
			<< p.show_EXP() << ','
			<< p.show_pass_count() << endl;

	
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "ע��ɹ���" << endl;
	}
	else if (type == "test_maker")
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�������û�����\n";
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> name;
		//getline(cin, name);
		/*�������*/
		bool user_exist = false;
		for (auto val : v_test_maker)
		{
			if (val.show_name() == name)
			{
				user_exist = true;
			}
		}
		if (user_exist)
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "���û����Ѵ��ڣ���ֱ�ӵ�½" << endl;
			return;
		}

		test_maker t(name);
		v_test_maker.push_back(t);

		/*д�ļ�*/
		fstream f_test_maker("test_maker.csv", ios::app);
		if (!f_test_maker) { cerr << "�޷����ļ�test_maker.csv" << endl; return; }
		f_test_maker << t.show_name() << ','
			<< t.show_level() << ','
			<< t.show_EXP() << ','
			<< t.show_word_num() << endl;

		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "ע��ɹ���" << endl;
	}
	else
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "����ȷ������\n";
	}

}