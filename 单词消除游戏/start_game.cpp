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

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		cout << "��ѡ���Ѷȣ�1-5����" << endl;
		cin >> difficulty;
		/*�����룺��ȷ�Լ��� ���пո�֮��Ļᵼ��fail*/
		cout << "���ס������ʣ�3s����ʧ����" ;

		int loc = 0;//�±�
		loc = rand() % (size / 5);
		switch (difficulty)
		{
		case 1://���ȡǰ1/5����
			//loc = rand() % (size / 5);//���ܻ����%�������õ�����
			break;
		case 2:
			loc+=size * 1 / 5;//���ܻ����%�������õ�����
			break;
		case 3:
			loc += size * 2 / 5;
			//loc = rand() % (size *  2/ 5);//���ܻ����%�������õ�����
			break;
		case 4:
			loc += size * 3 / 5;
			//loc = rand() % (size * 3/ 5);//���ܻ����%�������õ�����
			break;
		case 5:
			loc += size * 4 / 5;
			//loc = rand() % size;//���ܻ����%�������õ�����
			break;
		case 0:
			cout << "��Ϸ���˳�" << endl;
			return;
		default:
			break;
		}
		cout << word_set.at(loc);
		Sleep(3000);

		cout << "\r                                                            ";
		cout<<"\r������ղų��ֵĵ��ʣ�";
		cin >> input_word;
		/*���� ��ȷ�Լ���*/

		if (input_word == word_set.at(loc))//��ȷ
		{
			cout << "���뵥����ȷ�����سɹ�\n";
			/*���µȼ�������*/

		}
		else//����
		{
			cout << "���뵥�ʴ��󣬴���ʧ��\n";
		}
		cout << "����0�˳���Ϸ\n";
	}
}