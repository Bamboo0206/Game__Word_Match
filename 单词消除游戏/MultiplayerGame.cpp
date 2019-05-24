#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*����һ�����䲢�ȴ�*/
void newRoom(string &username_player,int roomNumber,  unsigned short int portA)
{
	vector<sysInfo>::iterator it_sysInfo;
	for (vector<room>::iterator it_room = v_room.begin(); it_room != v_room.end() ; it_room++)
	{
		if (it_room->roomNumber == roomNumber)
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
			it_sysInfo->oss << "�÷����Ѵ��ڡ���ѡ����������š�\n";
			return;
		}
	}

	/*��������*/
	{
		room r(roomNumber, username_player);
		r.portA = portA;
		v_room.push_back(r);//���õ��������캯��
	}

	int difficulty;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << "��ѡ���Ѷȣ�1~5����\n";
	mySend(portA);
	myRecv(portA);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->iss >> difficulty;
	if(difficulty<1|| difficulty>5)
		difficulty = difficulty % 5 + 1;//�ų���������

	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << "�ɹ������Ծ֡�\n�ȴ����ּ���...\n";
	mySend(portA);

	/*�ȴ�һ���˼���÷���*/
	vector<room>::iterator it_room;
	while (true)
	{
		for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);//��iterator��λ���÷��ŵķ���
		if (it_room->people_num == 2)
			break;
		else
			Sleep(200);
	}

	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << "���ҵ����֡�\n�ȴ�����...\n\0";
	mySend(portA);

	/*��ʼ��Ϸ*/

	/*���㵥�ʳ��ȣ�5���������ʸ�������ʾʱ��*/

	int round_current = difficulty * 2;
	it_room->word_num_to_pass = sqrt(round_current);
	it_room->display_time = -round_current * 2000 / 15 + 3000;
	it_room->display_time = it_room->display_time > 1000 ? it_room->display_time : 1000;//����1000
	//it_room->error_chance = -round_current * 2 / 15 + 3;
	//it_room->error_chance = it_room->error_chance > 1 ? it_room->error_chance : 1;//����1
		/*���*/
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << "*******************************************************************************************\n"
		<< "\t���A��" << it_room->nameA << "\tVs.\t���B��" << it_room->nameB << endl
		<< "                  �Ѷȣ�" << difficulty << "��\n"
		<< "���ʣ�" << it_room->word_num_to_pass << "������ʾʱ�䣺" << it_room->display_time << "����" << endl
		<< "*******************************************************************************************\n";
	mySend(portA);

	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
	it_sysInfo->oss << "*******************************************************************************************\n"
		<< "\t���A��" << it_room->nameA << "\tVs.\t���B��" << it_room->nameB<<endl
		<< "                  �Ѷȣ�" << difficulty << "��\n"
		<< "���ʣ�" << it_room->word_num_to_pass << "������ʾʱ�䣺" << it_room->display_time << "����" << endl
		<< "*******************************************************************************************\n";
	mySend(it_room->portB);

	Sleep(50);

	int loc = 0, wordlib_size = 0, word_passed = 0;//�±�,��������,��ͨ������
	wordlib_size = word_set.size();

	/*���word_num_to_pass �� display_time*/
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << it_room->word_num_to_pass << " " << it_room->display_time << "\n\0";
	mySend(portA);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
	it_sysInfo->oss << it_room->word_num_to_pass << " " << it_room->display_time << "\n\0";
	mySend(it_room->portB);
	Sleep(50);

	
	while ((it_room->word_num_to_pass )--)
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
		it_room->word = word_set.at(loc);
		/*���͵���*/
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->oss /*<< it_room->display_time << " " */<< word_set.at(loc)<<"\0";
		mySend(portA);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
		it_sysInfo->oss /*<< it_room->display_time << " " */<< word_set.at(loc) << "\0";
		mySend(it_room->portB);

		/*���ս��*/
		//char resultA,resultB;//���
		//double tempDA, tempDB;
		myRecv(portA);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->iss >> it_room->resultA >> it_room->timeA;
		myRecv(it_room->portB);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->iss >> it_room->resultB >> it_room->timeB;

		//it_room->timeA += tempDA;//��ʱ��;
		//it_room->timeB += tempDB;
		//it_room->resultA = resultA;
		//it_room->resultB = resultB;

		/*�ж�*/
		if (it_room->resultA&&it_room->resultB)//AB���Ա�ʱ��
		{
			if (it_room->timeA < it_room->timeB)
			{
				it_room->winA++;
			}
			else if (it_room->timeA > it_room->timeB)
			{
				it_room->winB++;
			}
		}
		else//��ȷ��win++
		{
			if(it_room->resultA)
				it_room->winA++;
			else if (it_room->resultB)
				it_room->winB++;
		}
	}
	/*���µȼ�������*/
	if (it_room->winA > it_room->winB)
	{
		vector<player>::iterator it_user_player;
		locate_player(it_room->nameA, it_user_player);
		it_user_player->inc_pass_count();
		int expA = it_user_player->update_EXP(difficulty);
		it_user_player->update_level();

		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->oss << "���Aʤ����Bʧ��\n"
			<< it_room->nameA <<" : EXP+" << expA << endl;

		print_player(it_room->nameA, portA);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
		it_sysInfo->oss << "���Aʤ����Bʧ��\n"
			<< it_room->nameA << " : EXP+" << expA << endl;
		print_player(it_room->nameB, it_room->portB);

	}
	else if (it_room->winA < it_room->winB)
	{
		vector<player>::iterator it_user_player;
		locate_player(it_room->nameB, it_user_player);
		it_user_player->inc_pass_count();
		int expB = it_user_player->update_EXP(difficulty);
		it_user_player->update_level();

		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		if (it_sysInfo == v_sysInfo.end()) { 
			cerr << "iterator out of range"; 
		return; }
		it_sysInfo->oss << "���Bʤ����Aʧ��\n"
			<< it_room->nameB << " : EXP+" << expB << endl;
		print_player(it_room->nameA, portA);
		
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
		it_sysInfo->oss << "���Bʤ����Aʧ��\n"
			<< it_room->nameB << " : EXP+" << expB << endl;
		print_player(it_room->nameB, it_room->portB);
	}
	else
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->oss << "ƽ��\n";
		print_player(it_room->nameA, portA);

		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
		it_sysInfo->oss << "ƽ��\n";
		print_player(it_room->nameB, it_room->portB);
	}

	/*ɾ���÷���*/
	it_room->people_num = 0;
	it_room->roomNumber = -1;
	return;
}


/*����һ�����䲢��ʼ��Ϸ*/
void joinRoom(string &username_player, int roomNumber, unsigned short int portB)
{
	vector<sysInfo>::iterator it_sysInfo;
	vector<room>::iterator it_room;
	for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);//��iterator��λ���÷��ŵķ���
	if (it_room == v_room.end())
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portB; it_sysInfo++);
		it_sysInfo->oss << "�öԾֲ����ڡ��봴���Ծֻ�����Ѵ��ڵĶԾ֡�\n";
		return;
	}
	if (it_room->people_num == 2)
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portB; it_sysInfo++);
		it_sysInfo->oss << "�öԾ����������봴���Ծֻ������δ���ĶԾ֡�\n";
		return;
	}
	it_room->nameB = username_player;
	it_room->people_num++;
	it_room->portB = portB;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portB; it_sysInfo++);
	it_sysInfo->oss << "���ҵ����֡�\n�ȴ�����...\n\0";
	mySend(portB);
	while (it_room->people_num!=0)//�ȴ��Ծֽ���
	{
		Sleep(2000);
		for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);
	}
}