#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*��Ϸÿһ�أ��������ݸùؿ��Ѷȣ���ʾһ�����ʣ�һ��ʱ��󵥴���ʧ��
��������Ҫ����Ӧ�ط�����ո���ʾ����ʧ�ĵ��ʣ����������������ȷ��Ϊͨ����*/

bool one_round(string name, unsigned short int port);//һ�أ����سɹ�����true//����pass_count+1

void start_game(string &username_player, unsigned short int port)
{
	bool finish = false;
	string input_word;
	int difficulty = 1, size = 0;

	size = word_set.size();
	if (!size) { cout << "�ʿ�Ϊ�գ�������ӵ���\n"; return ; }

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		if (one_round(username_player,port))//���سɹ�
		{
			cout << "��ѡ����һ��0/�˳�1��Ĭ�ϼ�����\n";
		}
		else//����ʧ��
		{
			cout << "��ѡ�����³��Ըù�0/�˳�1��Ĭ�ϼ�����\n";
		}
		mySend(port);
		myRecv(port);
		cin >> finish;
		if (!cin)//������ȷ�Լ���
		{
			cerr << "input error!\n";
			cin.clear();
			cin.ignore(99999, '\n');//�����������з����������е���������
			continue;
		}
	}
	/*����û���Ϣ*/
	print_player(username_player);
	cout << "��Ϸ���˳�" << endl;
	//getchar();
	return;
}


bool one_round(string name, unsigned short int port)//һ�أ����سɹ�����true
{
	vector<player>::iterator it_user_player;
	locate_player(name, it_user_player);
	int round_current = it_user_player->show_pass_count() + 1;

	/*���㵥�ʳ��ȣ�5���������ʸ�������ʾʱ��*/
	int difficulty = 1, word_num_to_pass = 0, display_time = 0, error_chance = 0;
	difficulty = round_current / 3;
	difficulty = difficulty < 5 ? difficulty : 5;//����5��
	word_num_to_pass = sqrt(round_current);
	display_time = -round_current * 2000 / 15 + 3000;
	display_time = display_time > 1000 ? display_time : 1000;//����1000
	error_chance = -round_current * 2 / 15 + 3;
	error_chance = error_chance > 1 ? error_chance : 1;//����1
		/*���*/
	cout << "*********************************************************************\n"
		<< "                  ��" << round_current << "��                  \n"
		<< "�Ѷȣ�" << difficulty << "�������ʣ�" << word_num_to_pass << "������ʾʱ�䣺" << display_time << "����" << endl
		<< "����" << error_chance << "�δ������\n";
	mySend(port);
	double duration = 0;
	int loc = 0, wordlib_size = 0, word_passed = 0;//�±�,��������,��ͨ������
	wordlib_size = word_set.size();
	cout << word_num_to_pass << " " << error_chance << "\n\0";
	mySend(port);
	Sleep(50);

	word_passed = 0;
	while (word_passed < word_num_to_pass && error_chance >= 0)
	{
		/*���㵥���±�*/
		loc = rand() % (wordlib_size / 5);
		switch (difficulty)
		{
		case 1://���ȡǰ1/5����
			break;
		case 2:
			loc += wordlib_size * 1 / 5;
			break;
		case 3:
			loc += wordlib_size * 2 / 5;
			break;
		case 4:
			loc += wordlib_size * 3 / 5;
			break;
		case 5:
			loc += wordlib_size * 4 / 5;
			break;
		default:
			break;
		}

		/*���͵��ʺ���ʾʱ��*/
		cout << display_time << "\n"<< word_set.at(loc);
		mySend(port);

		/*���ս��*/
		myRecv(port);
		char result;//���
		double tempD;
		cin >> result >> tempD;

		duration += tempD;//��ʱ��;
		

		if (result=='1')//��ȷ
		{
			word_passed++;
		}
		else//����
		{
			if (--error_chance == -1)
			{
				break;
			}
		}
	}
	/*���µȼ�������*/
	if (word_passed == word_num_to_pass)
	{
		cout << "���سɹ�\n";
		vector<player>::iterator it_user_player;
		locate_player(name, it_user_player);
		it_user_player->inc_pass_count();
		it_user_player->update_EXP(duration, round_current);
		it_user_player->update_level();
		return true;
	}
	else
	{
		cout << "����ʧ��" << endl;
		return false;
	}

}
