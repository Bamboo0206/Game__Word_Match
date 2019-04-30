#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*��Ϸÿһ�أ��������ݸùؿ��Ѷȣ���ʾһ�����ʣ�һ��ʱ��󵥴���ʧ��
��������Ҫ����Ӧ�ط�����ո���ʾ����ʧ�ĵ��ʣ����������������ȷ��Ϊͨ����*/

bool one_round(int pass_count);//һ�أ����سɹ�����true

void start_game()
{
	bool finish = false;
	string input_word;
	int difficulty = 1, size = 0;

	size = word_set.size();
	if (!size) { cout << "�ʿ�Ϊ�գ�������ӵ���\n"; return ; }

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		if (one_round(it_user_player->show_pass_count()))
		{
			
		}



		cout << "��ѡ�񣺼�����Ϸ0/�˳�1��Ĭ�ϼ�����\n";
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
	print_player();
	cout << "��Ϸ���˳�" << endl;
	return;
}

void print_player()
{
	cout <<"name:"<< it_user_player->show_name() << '\t'
		<< "level:" << it_user_player->show_level() << '\t'
		<< "EXP:" << it_user_player->show_EXP() << '\t'
		<< "ͨ����:" << it_user_player->show_pass_count() << endl;
}
void print_test_maker()
{
	cout << "name:" << it_user_test_maker->show_name() << '\t'
		<< "level:" << it_user_test_maker->show_level() << '\t'
		<< "EXP:" << it_user_test_maker->show_EXP() << '\t'
		<< "���뵥����:" << it_user_test_maker->show_word_num() << endl;
}

bool one_round(int pass_count)//һ�أ����سɹ�����true
{
	/*���㵥�ʳ��ȣ�5���������ʸ�������ʾʱ��*/
	int difficulty = 1, word_num_to_pass = 0, display_time = 0, error_chance = 0;
	difficulty = pass_count / 3;
	difficulty = difficulty < 5 ? difficulty : 5;//����5��
	word_num_to_pass = pass_count + 1;
	display_time = -pass_count * 2000 / 15 + 3000;
	display_time = display_time > 1000 ? display_time : 1000;//����1000
	error_chance = -pass_count * 2 / 15;
	error_chance = error_chance > 1 ? error_chance : 1;//����1
		/*���*/
	cout << "�Ѷȣ�" << difficulty << "�������ʣ�" << word_num_to_pass << "������ʾʱ�䣺" << display_time << "����" << endl
		<< "����" << error_chance << "�δ������\n";

	string input_word;//�û�����ĵ���
	bool finish = false, pass = true;
	int loc = 0, wordlib_size = 0;//�±�,��������
	wordlib_size = word_set.size();


	pass = true;
	for (int i = 1; i <= word_num_to_pass; i++)
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
		cout << "���ס������ʣ�<<" << display_time << "�������ʧ����"
			<< word_set.at(loc);
		Sleep(display_time);


		cout << "\r                                                            ";
		cout << "\r������ղų��ֵĵ��ʣ�";
		cin >> input_word;
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

		}
		else//����
		{
			cout << "���뵥�ʴ��󣬴���ʧ��\t�ղ���ʾ�ĵ����ǣ�" << word_set.at(loc) << endl;
			if (--error_chance == -1)
			{
				pass = false;
				break;
			}
			cout << "������" << error_chance << "�δ������" << endl;
		}
	}
	/*���µȼ�������*/
	if (pass)
	{
		cout << "���سɹ�\n";
		it_user_player->inc_pass_count();
		it_user_player->update_EXP(difficulty);//????
		it_user_player->update_level();
		return true;
	}
	else
	{
		cout << "����ʧ��" << endl;
		return false;
	}

}
