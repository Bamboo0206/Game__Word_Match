#include"header.h"

/*ȫ�ֱ���*/
extern vector<test_maker>::iterator it_user_test_maker;//��ǰϵͳ�û�
extern set<string> word_set;//���ʼ���

void add_word()
{
	bool finish = false;
	cout << "����ѡ�񣺼������뵥��0/�˳�1\n";
	cin >> finish;
	pair<set<string>::iterator, bool> insert_result;//
	string new_word;
	//set<string>::iterator it_word;
	while (!finish)
	{
		cin >> new_word;
		/*�����룺��ȷ�Լ���*/
		insert_result = word_set.insert(new_word);//insert����pair
		if (insert_result.second)//����ɹ�����
		{
			cout << "�ɹ���ӵ��ʣ�" << *insert_result.first << endl;

			/*�����������޸ģ�������������ֵ���ȼ�*/
			it_user_test_maker->inc_word_num();

		}
		else
		{
			cout << "�õ����Ѵ���\n";
		}



		cout << "��ѡ�񣺼������뵥��0/�˳�1\n";
		cin >> finish;
	}
}