#include"header.h"
#include"function_declaration.h"

/*ȫ�ֱ���*/
vector<player> v_player;//����player
vector<test_maker> v_test_maker;//����test_maker
vector<player>::iterator it_user_player;//��ǰϵͳ�û�
vector<test_maker>::iterator it_user_test_maker;
vector<string> word_set;//���ʼ���
//set<string,my_shorter> word_set;//���ʼ���//ʹ���Զ���my_shorter�Ƚϴ�С



int main()
{
	/*��ʼ�� ������*/
	//it_user_player == v_player.();
	//it_user_test_maker == v_test_maker.begin();
	srand((unsigned int) time(NULL));
	/*����*/
	string option;
	while (true)
	{
		cout << "��ѡ�������\n";
		getline(cin, option);
		/*ע��*/
		if (option == "sign_up")
		{
			sign_up();
		}
		/*��½*/
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
			/*����Ƿ��½*/

			log_out();
		}
		/*��ѯ�����������а��*/
		else if (option == "rank")
		{
			cout << "��ѡ��Ҫ�鿴�����а�player/test_maker����\n";
			string choice;
			cin >> choice;
			if (choice == "player")rank_player();
			else if (choice == "test_maker")rank_test_maker();
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
		else
			cout << "�Ƿ�����" << endl;
	}
	return 0;
}

