//#include"header.h"
//#include"variable.h"
//#include"function_declaration.h"
//
///*����һ�����䲢�ȴ�*/
//void newRoom(string &username_player,int roomNumber,  unsigned short int portA)
//{
//	for (vector<room>::iterator it_room = v_room.begin(); it_room != v_room.end() ; it_room++)
//	{
//		if (it_room->roomNumber == roomNumber)
//		{
//			cout << "�÷����Ѵ��ڡ���ѡ����������š�\n";
//			return;
//		}
//	}
//
//	/*��������*/
//	{
//		room r(roomNumber, username_player);
//		v_room.push_back(r);//���õ��������캯��
//	}
//
//	int difficulty;
//	cout << "��ѡ���Ѷȣ�1~5����\n";
//	cin >> difficulty;
//	difficulty = difficulty % 5 + 1;//�ų���������
//
//	cout << "�ɹ��������䡣\n�ȴ����ּ���...\n";
//	mySend(portA);
//
//	/*�ȴ�һ���˼���÷���*/
//	vector<room>::iterator it_room;
//	while (true)
//	{
//		for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);//��iterator��λ���÷��ŵķ���
//		if (it_room->people_num == 2)
//			break;
//		else
//			Sleep(200);
//	}
//
//	cout << "���ҵ����֡�\n�ȴ�����...\n";
//	mySend(portA);
//
//	/*��ʼ��Ϸ*/
//
//	/*���㵥�ʳ��ȣ�5���������ʸ�������ʾʱ��*/
//
//	int round_current = difficulty * 2;
//	it_room->word_num_to_pass = sqrt(round_current);
//	it_room->display_time = -round_current * 2000 / 15 + 3000;
//	it_room->display_time = it_room->display_time > 1000 ? it_room->display_time : 1000;//����1000
//	//it_room->error_chance = -round_current * 2 / 15 + 3;
//	//it_room->error_chance = it_room->error_chance > 1 ? it_room->error_chance : 1;//����1
//		/*���*/
//	cout << "*********************************************************************\n"
//		<< "\t���A��" << it_room->nameA << "\tVs.\t���B��" << it_room->nameB
//		<< "                  �Ѷȣ�" << difficulty << "��\n"
//		<< "���ʣ�" << it_room->word_num_to_pass << "������ʾʱ�䣺" << it_room->display_time << "����" << endl;
//		
//	mySend(portA);
//	mySend(it_room->portB);
//
//	int loc = 0, wordlib_size = 0, word_passed = 0;//�±�,��������,��ͨ������
//	wordlib_size = word_set.size();
//	cout << it_room->word_num_to_pass << "\n\0";
//	mySend(portA);
//	mySend(it_room->portB);
//	Sleep(50);
//
//	word_passed = 0;
//	while (word_passed < it_room->word_num_to_pass )
//	{
//		/*���㵥���±�*/
//		loc = rand() % (wordlib_size / 5);
//		switch (difficulty)
//		{
//		case 1://���ȡǰ1/5����
//			break;
//		case 2:
//			loc += wordlib_size * 1 / 5;
//			break;
//		case 3:
//			loc += wordlib_size * 2 / 5;
//			break;
//		case 4:
//			loc += wordlib_size * 3 / 5;
//			break;
//		case 5:
//			loc += wordlib_size * 4 / 5;
//			break;
//		default:
//			break;
//		}
//		it_room->word = word_set.at(loc);
//		/*���͵��ʺ���ʾʱ��*/
//		cout << it_room->display_time << "\n" << word_set.at(loc);
//		mySend(port);
//
//		/*���ս��*/
//		char resultA,resultB;//���
//		double tempDA, tempDB;
//		myRecv(portA);
//		cin >> resultA >> tempDA;
//		myRecv(portB);
//		cin >> resultB >> tempDB;
//
//		it_room->timeA += tempDA;//��ʱ��;
//		it_room->timeB += tempDB;
//		it_room->resultA = resultA;
//		it_room->resultB = resultB;
//
//		if()
//	}
//	/*���µȼ�������*/
//	if (word_passed == word_num_to_pass)
//	{
//		cout << "���سɹ�\n";
//		vector<player>::iterator it_user_player;
//		locate_player(name, it_user_player);
//		it_user_player->inc_pass_count();
//		it_user_player->update_EXP(duration, round_current);
//		it_user_player->update_level();
//		return true;
//	}
//	else
//	{
//		cout << "����ʧ��" << endl;
//		return false;
//	}
//
//
//}
//
//
///*����һ�����䲢��ʼ��Ϸ*/
//void newRoom(string &username_player, int roomNumber, unsigned short int portB)
//{
//	vector<room>::iterator it_room;
//	for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);//��iterator��λ���÷��ŵķ���
//	if (it_room == v_room.end())
//	{
//		cout << "�öԾֲ����ڡ��봴���Ծֻ�����Ѵ��ڵĶԾ֡�\n";
//		return;
//	}
//	if (it_room->people_num == 2)
//	{
//		cout << "�öԾ����������봴���Ծֻ������δ���ĶԾ֡�\n";
//		return;
//	}
//	it_room->nameB = username_player;
//	it_room->people_num++;
//	it_room->portB = portB;
//}