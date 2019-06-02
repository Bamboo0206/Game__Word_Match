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
	vector<sysInfo>::iterator it_sysInfo;
	size = word_set.size();
	if (!size) 
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "�ʿ�Ϊ�գ�������ӵ���\n";
		return;
	}

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		if (one_round(username_player,port))//���سɹ�
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "��ѡ����һ��0/�˳�1��Ĭ�ϼ�����\n";
		}
		else//����ʧ��
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "��ѡ�����³��Ըù�0/�˳�1��Ĭ�ϼ�����\n";
		}
		mySend(port);
		myRecv(port);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> finish;
	}
	/*����û���Ϣ*/
	print_player(username_player, port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "��Ϸ���˳�" << endl;
	//getchar();
	return;
}


bool one_round(string name, unsigned short int port)//һ�أ����سɹ�����true
{
	vector<sysInfo>::iterator it_sysInfo;
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
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "*********************************************************************\n"
		<< "                  ��" << round_current << "��                  \n"
		<< "�Ѷȣ�" << difficulty << "�������ʣ�" << word_num_to_pass << "������ʾʱ�䣺" << display_time << "����" << endl
		<< "����" << error_chance << "�δ������\n";
	mySend(port);
	double duration = 0;
	int loc = 0, wordlib_size = 0, word_passed = 0;//�±�,��������,��ͨ������
	wordlib_size = word_set.size();
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << word_num_to_pass << " " << error_chance << "\n\0";
	mySend(port);
	Sleep(50);

	word_passed = 0;
	while (word_passed < word_num_to_pass && error_chance >= 0)
	{
		/*�������Ѷȷ�Ϊ5���������Ѷ������������ȡ����*/
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

		/*���������͵��ʺ͸õ�����ʾ��ʱ�䣬�ͻ��˷����û��Ƿ��Ժʹ����ʱ*/
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << display_time << "\n"<< word_set.at(loc);
		mySend(port);

		/*���ս��*/
		myRecv(port);
		char result;//���
		double tempD;
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->iss >> result >> tempD;

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
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "���سɹ�\n";

		vector<player>::iterator it_user_player;
		locate_player(name, it_user_player);

		it_sysInfo->oss << "EXP+" << it_user_player->update_EXP(duration, round_current) << endl;
		locate_player(name, it_user_player);
		it_user_player->inc_pass_count();
		it_user_player->update_level();
		return true;
	}
	else
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "����ʧ��" << endl;
		return false;
	}

}
