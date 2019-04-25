#include"header.h"
#include"variable.h"

void add_word()
{
	bool finish = false;
	//cout << "输入选择：输入单词0/退出1\n";
	//cin >> finish;
	//pair<set<string>::iterator, bool> insert_result;//使用pair！
	string new_word;
	//set<string>::iterator it_word;
	while (!finish)
	{
		cout << "请输入新增的单词：" << endl;
		cin >> new_word;
		/*待加入：正确性检验 若有空格之类的会导致fail*/
		//insert_result = word_set.insert(new_word);//insert返回pair
		vector<string>::iterator insert_result;
		insert_result = find(word_set.begin(), word_set.end(), new_word);
		if (insert_result== word_set.end())//插入成功检验:单词不存在
		{
			word_set.push_back(new_word);
			cout << "成功添加单词：" << word_set.back() << endl;

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
	cout << "level:" << it_user_test_maker->show_level
		<< "\tEXP:" << it_user_test_maker->show_EXP << endl;
}