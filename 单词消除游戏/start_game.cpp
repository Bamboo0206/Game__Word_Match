#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*��Ϸÿһ�أ��������ݸùؿ��Ѷȣ���ʾһ�����ʣ�һ��ʱ��󵥴���ʧ��
��������Ҫ����Ӧ�ط�����ո���ʾ����ʧ�ĵ��ʣ����������������ȷ��Ϊͨ����*/

void start_game(vector<player>::iterator &it_user_player)
{
	bool finish = false;
	string input_word;
	int difficulty = 1, size = 0;

	size = word_set.size();
	if (!size) { cout << "�ʿ�Ϊ�գ�������ӵ���\n"; return ; }

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		cout << "��ѡ���Ѷȣ�1-5����" << endl;
		cin >> difficulty;
		if (!cin)//������ȷ�Լ���
		{
			cerr << "input error!\n";
			cin.clear();
			cin.ignore(99999, '\n');//�����������з����������е���������
			continue;
		}

		cout << "���ס������ʣ�3s����ʧ����" ;

		int loc = 0;//�±�
		loc = rand() % (size / 5);
		switch (difficulty)
		{
		case 1://���ȡǰ1/5����
			break;
		case 2:
			loc += size * 1 / 5;
			break;
		case 3:
			loc += size * 2 / 5;
			break;
		case 4:
			loc += size * 3 / 5;
			break;
		case 5:
			loc += size * 4 / 5;
			break;
		default:
			cout << "�Ƿ�����" << endl;
			continue;//??
			break;
		}

		/*�������*/
		cout << word_set.at(loc);
		Sleep(3000);

		cout << "\r                                                            ";
		cout<<"\r������ղų��ֵĵ��ʣ�";
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
			cout << "���뵥����ȷ�����سɹ�\n";
			/*���µȼ�������*/
			it_user_player->update_EXP(difficulty);
			it_user_player->update_level();
			it_user_player->inc_pass_count();
		}
		else//����
		{
			cout << "���뵥�ʴ��󣬴���ʧ��\t�ղ���ʾ�ĵ����ǣ�" << word_set.at(loc) << endl;
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
	print_player(it_user_player);
	cout << "��Ϸ���˳�" << endl;
	return;
}

void print_player(vector<player>::iterator &it_user_player)
{
	cout <<"name:"<< it_user_player->show_name() << '\t'
		<< "level:" << it_user_player->show_level() << '\t'
		<< "EXP:" << it_user_player->show_EXP() << '\t'
		<< "ͨ����:" << it_user_player->show_pass_count() << endl;
}
void print_test_maker(vector<test_maker>::iterator &it_user_test_maker)
{
	cout << "name:" << it_user_test_maker->show_name() << '\t'
		<< "level:" << it_user_test_maker->show_level() << '\t'
		<< "EXP:" << it_user_test_maker->show_EXP() << '\t'
		<< "���뵥����:" << it_user_test_maker->show_word_num() << endl;
}