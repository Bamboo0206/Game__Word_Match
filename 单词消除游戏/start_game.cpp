#include"header.h"
#include"variable.h"

/*��Ϸÿһ�أ��������ݸùؿ��Ѷȣ���ʾһ�����ʣ�һ��ʱ��󵥴���ʧ��
��������Ҫ����Ӧ�ط�����ո���ʾ����ʧ�ĵ��ʣ����������������ȷ��Ϊͨ����*/

void start_game()
{
	bool finish = false;
	//pair<set<string>::iterator, bool> insert_result;//ʹ��pair��
	string input_word;
	set<string>::iterator word_it = word_set.begin();
	int difficulty = 1, size = 0;

	size = word_set.size();
	if (!size) { cout << "�ʿ�Ϊ�գ�������ӵ���\n"; return ; }

	while (!finish)
	{
		cout << "��ѡ���Ѷȣ�1-5����" << endl;
		cin >> difficulty;
		/*�����룺��ȷ�Լ��� ���пո�֮��Ļᵼ��fail*/
		cout << "�����ǣ�" << endl;

		int loc = 0;//�±�
		switch (difficulty)
		{
		case 1://���ȡǰ1/5����
			loc = rand() % (size / 5);//���ܻ����%�������õ�����
			cout << *(word_set.begin() + loc);

		default:
			break;
		}
		Sleep(300);
	}
}