#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*���ļ�����������ӵ���*/
void add_word(string &username_test_maker, unsigned short int port)
{
	bool finish = false;
	string new_word;
	while (!finish)
	{
		vector<sysInfo>::iterator it_sysInfo;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�����������ĵ��ʣ�" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> new_word;
		vector<string>::iterator insert_result;
		insert_result = find(word_set.begin(), word_set.end(), new_word);
		if (insert_result== word_set.end())//����ɹ�����:���ʲ�����
		{
			word_set.push_back(new_word);
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "�ɹ���ӵ��ʣ�" << word_set.back()/*����ĩβԪ������*/ << endl;
			/*д���ļ�*/
			fstream f_wordlib("wordlib.csv", ios::app);
			if (!f_wordlib) { cerr << "�޷����ļ�wordlib.csv" << endl; return; }
			f_wordlib << new_word << endl;

			/*�����������޸ģ�������������ֵ���ȼ�*/
			vector<test_maker>::iterator it_user_test_maker;
			locate_test_maker(username_test_maker, it_user_test_maker);
			it_user_test_maker->inc_word_num();
			it_user_test_maker->update_EXP(new_word);
			it_user_test_maker->update_level();
		}
		else
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "�õ����Ѵ���\n";
		}

		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "��ѡ�񣺼������뵥��0/�˳�1\n";
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> finish;
	}
	print_test_maker(username_test_maker, port);
}