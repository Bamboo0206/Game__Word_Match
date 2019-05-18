#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*��Ϸÿһ�أ��������ݸùؿ��Ѷȣ���ʾһ�����ʣ�һ��ʱ��󵥴���ʧ��
��������Ҫ����Ӧ�ط�����ո���ʾ����ʧ�ĵ��ʣ����������������ȷ��Ϊͨ����*/

bool one_round(string name);//һ�أ����سɹ�����true//����pass_count+1

void start_game(string &username_player)
{
	bool finish = false;
	string input_word;
	int difficulty = 1, size = 0;

	size = word_set.size();
	if (!size) { cout << "�ʿ�Ϊ�գ�������ӵ���\n"; return ; }

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		if (one_round(username_player))//���سɹ�
		{
			cout << "��ѡ����һ��0/�˳�1��Ĭ�ϼ�����\n";
		}
		else//����ʧ��
		{
			cout << "��ѡ�����³��Ըù�0/�˳�1��Ĭ�ϼ�����\n";
		}
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
	getchar();
	return;
}


bool one_round(string name)//һ�أ����سɹ�����true
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

	string input_word;//�û�����ĵ���
	clock_t start = 0, finish = 0;//��ʱ��
	double duration = 0;
	int loc = 0, wordlib_size = 0, word_passed = 0;//�±�,��������,��ͨ������
	wordlib_size = word_set.size();

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

		/*�������*/
		cout << "���ס������ʣ�" << display_time << "�������ʧ����"
			<< word_set.at(loc);
		Sleep(display_time);


		cout << "\r                                                            ";
		cout << "\r������ղų��ֵĵ��ʣ�";
		/*���ģ���ʱ��*/
		start = clock();//������ʱ��
		cin >> input_word;
		finish = clock();//�رռ�ʱ��
		duration += (double)(finish - start) / CLOCKS_PER_SEC;//��ʱ��
		cout << "��ʱ" << (double)(finish - start) / CLOCKS_PER_SEC << "��" << endl;
		/*������ȷ�Լ���*/
		if (!cin)
		{
			cerr << "input error!\n";
			cin.clear();
			cin.ignore(99999, '\n');//�����������з����������е���������
			continue;
		}


		if (input_word == word_set.at(loc))//��ȷ
		{
			cout << "���뵥����ȷ\n";
			word_passed++;
		}
		else//����
		{
			cout << "���뵥�ʴ���\t�ղ���ʾ�ĵ����ǣ�" << word_set.at(loc) << endl;
			Sleep(2000);
			if (--error_chance == -1)
			{
				break;
			}
			cout << "������" << error_chance << "�δ������" << endl;
		}
	}
	/*���µȼ�������*/
	if (word_passed == word_num_to_pass)
	{
		cout << "���سɹ�\n";
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
