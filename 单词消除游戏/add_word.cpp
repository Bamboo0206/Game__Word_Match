#include"header.h"
#include"variable.h"
#include"function_declaration.h"

void add_word(vector<test_maker>::iterator &it_user_test_maker)
{
	bool finish = false;
	string new_word;
	while (!finish)
	{
		cout << "请输入新增的单词：" << endl;
		cin >> new_word;
		/*正确性检验 若有空格之类的会导致fail*/
		if (!cin)
		{
			cerr << "input error!\n";
			cin.clear();
			cin.ignore(99999, '\n');//放弃包含换行符的输入流中的所有内容
			continue;
		}
		vector<string>::iterator insert_result;
		insert_result = find(word_set.begin(), word_set.end(), new_word);
		if (insert_result== word_set.end())//插入成功检验:单词不存在
		{
			word_set.push_back(new_word);
			cout << "成功添加单词：" << word_set.back() << endl;
			/*写入文件*/
			fstream f_wordlib("wordlib.csv", ios::app);
			if (!f_wordlib) { cerr << "无法打开文件wordlib.csv" << endl; return; }
			f_wordlib << new_word << endl;

			/*出题者属性修改：单词数、经验值、等级*/
			it_user_test_maker->inc_word_num();
			it_user_test_maker->update_EXP(new_word);
			it_user_test_maker->update_level();
		}
		else
		{
			cout << "该单词已存在\n";
		}

		cout << "请选择：继续输入单词0/退出1\n";
		cin >> finish;
	}
	print_test_maker(it_user_test_maker);
	getchar();//吞回车
}