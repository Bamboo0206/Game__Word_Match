#include"header.h"
#include"variable.h"

void add_word()
{
	bool finish = false;
	//cout << "����ѡ�����뵥��0/�˳�1\n";
	//cin >> finish;
	//pair<set<string>::iterator, bool> insert_result;//ʹ��pair��
	string new_word;
	//set<string>::iterator it_word;
	while (!finish)
	{
		cout << "�����������ĵ��ʣ�" << endl;
		cin >> new_word;
		/*�����룺��ȷ�Լ��� ���пո�֮��Ļᵼ��fail*/
		//insert_result = word_set.insert(new_word);//insert����pair
		vector<string>::iterator insert_result;
		insert_result = find(word_set.begin(), word_set.end(), new_word);
		if (insert_result== word_set.end())//����ɹ�����:���ʲ�����
		{
			word_set.push_back(new_word);
			cout << "�ɹ���ӵ��ʣ�" << word_set.back() << endl;

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
	cout << "level:" << it_user_test_maker->show_level
		<< "\tEXP:" << it_user_test_maker->show_EXP << endl;
}