#include"header.h"
#include"variable.h"
#include"function_declaration.h"

void add_word(vector<test_maker>::iterator &it_user_test_maker)
{
	bool finish = false;
	string new_word;
	while (!finish)
	{
		cout << "�����������ĵ��ʣ�" << endl;
		cin >> new_word;
		/*��ȷ�Լ��� ���пո�֮��Ļᵼ��fail*/
		if (!cin)
		{
			cerr << "input error!\n";
			cin.clear();
			cin.ignore(99999, '\n');//�����������з����������е���������
			continue;
		}
		vector<string>::iterator insert_result;
		insert_result = find(word_set.begin(), word_set.end(), new_word);
		if (insert_result== word_set.end())//����ɹ�����:���ʲ�����
		{
			word_set.push_back(new_word);
			cout << "�ɹ���ӵ��ʣ�" << word_set.back() << endl;
			/*д���ļ�*/
			fstream f_wordlib("wordlib.csv", ios::app);
			if (!f_wordlib) { cerr << "�޷����ļ�wordlib.csv" << endl; return; }
			f_wordlib << new_word << endl;

			/*�����������޸ģ�������������ֵ���ȼ�*/
			it_user_test_maker->inc_word_num();
			it_user_test_maker->update_EXP(new_word);
			it_user_test_maker->update_level();
		}
		else
		{
			cout << "�õ����Ѵ���\n";
		}

		cout << "��ѡ�񣺼������뵥��0/�˳�1\n";
		cin >> finish;
	}
	print_test_maker(it_user_test_maker);
	getchar();//�̻س�
}