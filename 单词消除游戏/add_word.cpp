#include"header.h"

/*全局变量*/
extern vector<test_maker>::iterator it_user_test_maker;//当前系统用户
extern set<string> word_set;//单词集合

void add_word()
{
	bool finish = false;
	cout << "输入选择：继续输入单词0/退出1\n";
	cin >> finish;
	pair<set<string>::iterator, bool> insert_result;//
	string new_word;
	//set<string>::iterator it_word;
	while (!finish)
	{
		cin >> new_word;
		/*待加入：正确性检验*/
		insert_result = word_set.insert(new_word);//insert返回pair
		if (insert_result.second)//插入成功检验
		{
			cout << "成功添加单词：" << *insert_result.first << endl;

			/*出题者属性修改：单词数、经验值、等级*/
			it_user_test_maker->inc_word_num();

		}
		else
		{
			cout << "该单词已存在\n";
		}



		cout << "请选择：继续输入单词0/退出1\n";
		cin >> finish;
	}
}