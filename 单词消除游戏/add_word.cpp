#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*向文件和容器中添加单词*/
void add_word(string &username_test_maker, unsigned short int port)
{
	bool finish = false;
	string new_word;
	while (!finish)
	{
		vector<sysInfo>::iterator it_sysInfo;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "请输入新增的单词：" << endl;
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> new_word;
		vector<string>::iterator insert_result;
		insert_result = find(word_set.begin(), word_set.end(), new_word);
		if (insert_result== word_set.end())//插入成功检验:单词不存在
		{
			word_set.push_back(new_word);
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "成功添加单词：" << word_set.back()/*返回末尾元素引用*/ << endl;
			/*写入文件*/
			fstream f_wordlib("wordlib.csv", ios::app);
			if (!f_wordlib) { cerr << "无法打开文件wordlib.csv" << endl; return; }
			f_wordlib << new_word << endl;

			/*出题者属性修改：单词数、经验值、等级*/
			vector<test_maker>::iterator it_user_test_maker;
			locate_test_maker(username_test_maker, it_user_test_maker);
			it_user_test_maker->inc_word_num();
			it_user_test_maker->update_EXP(new_word);
			it_user_test_maker->update_level();
		}
		else
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "该单词已存在\n";
		}

		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "请选择：继续输入单词0/退出1\n";
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> finish;
	}
	print_test_maker(username_test_maker, port);
}