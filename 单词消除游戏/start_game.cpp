#include"header.h"
#include"variable.h"

/*��Ϸÿһ�أ��������ݸùؿ��Ѷȣ���ʾһ�����ʣ�һ��ʱ��󵥴���ʧ��
��������Ҫ����Ӧ�ط�����ո���ʾ����ʧ�ĵ��ʣ����������������ȷ��Ϊͨ����*/

void start_game()
{
	bool finish = false;
	//pair<set<string>::iterator, bool> insert_result;//ʹ��pair��
	string input_word;
	//set<string>::iterator word_it = word_set.begin();
	int difficulty = 1, size = 0;

	size = word_set.size();
	if (!size) { cout << "�ʿ�Ϊ�գ�������ӵ���\n"; return ; }

	while (!finish)
	{
		cout << "��ѡ���Ѷȣ�1-5����" << endl;
		cin >> difficulty;
		/*�����룺��ȷ�Լ��� ���пո�֮��Ļᵼ��fail*/
		cout << "���ס������ʣ�3s����ʧ����" ;

		int loc = 0;//�±�
		switch (difficulty)
		{
		case 1://���ȡǰ1/5����
			loc = rand() % (size / 5);//���ܻ����%�������õ�����
			cout << *(word_set.begin() + loc);
			break;
		case 2:


		default:
			break;
		}
		Sleep(300);

		cout << "\r������ղų��ֵĵ��ʣ�";
		cin >> input_word;
		/*���� ��ȷ�Լ���*/

		if (input_word == *(word_set.begin() + loc))//��ȷ
		{
			cout << "���뵥����ȷ�����سɹ�\n";
			/*���µȼ�������*/

		}
		else//����
		{
			cout << "���뵥�ʴ��󣬴���ʧ��\n";
		}

	}
}