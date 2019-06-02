#include"header.h"
#include"class.h"
#include"function_declaration.h"

/*ȫ�ֱ���*/
vector<player> v_player;//����player
vector<test_maker> v_test_maker;//����test_maker
vector<player>::iterator it_user_player;//��ǰϵͳ�û�
vector<test_maker>::iterator it_user_test_maker;
vector<string> word_set;//���ʼ���
string username_player, username_test_maker;//��ǰ�û����û���



int main()
{
	srand((unsigned int) time(NULL));
	read_wordlib();
	read_player();
	read_test_maker();
	it_user_player = v_player.end();
	it_user_test_maker = v_test_maker.end();

	/*����*/
	string option;
	while (true)
	{
		cout<<"*****************************************\n"
			<<"ע�᣺sign_up\n"
			<<"��½��log_in\n"
			<<"�����ߣ���ʼ��Ϸ��start_game\n"
			<<"�����ߣ��������ʣ�add_word\n"
			<<"���а�rank\n"
			<<"���Ҵ����ߣ�search_player\n"
			<<"���ҳ����ߣ�search_test_maker\n"
			<<"�ǳ���log_out\n"
			<<"�˳�����quit\n"
			<<"*****************************************\n"
			<< "��ѡ�������\n";
		getline(cin, option);
		/*ע��*/
		if (option == "sign_up")
		{
			sign_up();
		}
		/*��½*///����ѵ�½�����
		else if (option == "log_in")
		{
			log_in();
		}
		/*��ʼ��Ϸ*/
		else if (option == "start_game")
		{
			/*����Ƿ��½*/
			if (it_user_player == v_player.end())
			{
				cout << "���ȵ�½\n";
			}
			else
			{
				start_game();
			}
		}
		/*��������*/
		else if (option == "add_word")
		{
			/*����Ƿ��½*/
			if (it_user_test_maker == v_test_maker.end())//��������
			{
				cout << "���ȵ�½\n";
			}
			else
			{
				add_word();
			}
		}

		/*�ǳ�*/
		else if (option == "log_out")
		{
			log_out();
		}
		/*���а�*/
		else if (option == "rank")
		{
			cout << "��ѡ��Ҫ�鿴�����а�player/test_maker����\n";
			string choice;
			cin >> choice;
			if (choice == "player")rank_player();
			else if (choice == "test_maker")rank_test_maker();
			else cout << "�Ƿ�����" << endl;
		}

		/*����ɫ���Բ�ѯ*/
		else if (option == "search_player")
		{
			search_player();
		}
		else if (option == "search_test_maker")
		{
			search_test_maker();
		}

		/*�˳�ϵͳ ��Ҫд�ļ�*/
		else if (option == "quit")
		{
			write_participants();
			break;
		}
		else
			cout << "�Ƿ�����" << endl;
	}
	return 0;
}

