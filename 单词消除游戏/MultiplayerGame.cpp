//#include"header.h"
//#include"variable.h"
//#include"function_declaration.h"
//
///*创建一个房间并等待*/
//void newRoom(string &username_player,int roomNumber,  unsigned short int portA)
//{
//	for (vector<room>::iterator it_room = v_room.begin(); it_room != v_room.end() ; it_room++)
//	{
//		if (it_room->roomNumber == roomNumber)
//		{
//			cout << "该房号已存在。请选择其他房间号。\n";
//			return;
//		}
//	}
//
//	/*创建房间*/
//	{
//		room r(roomNumber, username_player);
//		v_room.push_back(r);//会用到拷贝构造函数
//	}
//
//	int difficulty;
//	cout << "请选择难度（1~5）：\n";
//	cin >> difficulty;
//	difficulty = difficulty % 5 + 1;//排除错误输入
//
//	cout << "成功创建房间。\n等待对手加入...\n";
//	mySend(portA);
//
//	/*等待一个人加入该房间*/
//	vector<room>::iterator it_room;
//	while (true)
//	{
//		for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);//将iterator定位到该房号的房间
//		if (it_room->people_num == 2)
//			break;
//		else
//			Sleep(200);
//	}
//
//	cout << "已找到对手。\n等待开局...\n";
//	mySend(portA);
//
//	/*开始游戏*/
//
//	/*计算单词长度（5级），单词个数，显示时间*/
//
//	int round_current = difficulty * 2;
//	it_room->word_num_to_pass = sqrt(round_current);
//	it_room->display_time = -round_current * 2000 / 15 + 3000;
//	it_room->display_time = it_room->display_time > 1000 ? it_room->display_time : 1000;//下限1000
//	//it_room->error_chance = -round_current * 2 / 15 + 3;
//	//it_room->error_chance = it_room->error_chance > 1 ? it_room->error_chance : 1;//下限1
//		/*输出*/
//	cout << "*********************************************************************\n"
//		<< "\t玩家A：" << it_room->nameA << "\tVs.\t玩家B：" << it_room->nameB
//		<< "                  难度：" << difficulty << "级\n"
//		<< "单词：" << it_room->word_num_to_pass << "个，显示时间：" << it_room->display_time << "毫秒" << endl;
//		
//	mySend(portA);
//	mySend(it_room->portB);
//
//	int loc = 0, wordlib_size = 0, word_passed = 0;//下标,单词数量,已通过数量
//	wordlib_size = word_set.size();
//	cout << it_room->word_num_to_pass << "\n\0";
//	mySend(portA);
//	mySend(it_room->portB);
//	Sleep(50);
//
//	word_passed = 0;
//	while (word_passed < it_room->word_num_to_pass )
//	{
//		/*计算单词下标*/
//		loc = rand() % (wordlib_size / 5);
//		switch (difficulty)
//		{
//		case 1://随机取前1/5单词
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
//		/*发送单词和显示时间*/
//		cout << it_room->display_time << "\n" << word_set.at(loc);
//		mySend(port);
//
//		/*接收结果*/
//		char resultA,resultB;//结果
//		double tempDA, tempDB;
//		myRecv(portA);
//		cin >> resultA >> tempDA;
//		myRecv(portB);
//		cin >> resultB >> tempDB;
//
//		it_room->timeA += tempDA;//算时间;
//		it_room->timeB += tempDB;
//		it_room->resultA = resultA;
//		it_room->resultB = resultB;
//
//		if()
//	}
//	/*更新等级、经验*/
//	if (word_passed == word_num_to_pass)
//	{
//		cout << "闯关成功\n";
//		vector<player>::iterator it_user_player;
//		locate_player(name, it_user_player);
//		it_user_player->inc_pass_count();
//		it_user_player->update_EXP(duration, round_current);
//		it_user_player->update_level();
//		return true;
//	}
//	else
//	{
//		cout << "闯关失败" << endl;
//		return false;
//	}
//
//
//}
//
//
///*加入一个房间并开始游戏*/
//void newRoom(string &username_player, int roomNumber, unsigned short int portB)
//{
//	vector<room>::iterator it_room;
//	for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);//将iterator定位到该房号的房间
//	if (it_room == v_room.end())
//	{
//		cout << "该对局不存在。请创建对局或加入已存在的对局。\n";
//		return;
//	}
//	if (it_room->people_num == 2)
//	{
//		cout << "该对局人已满。请创建对局或加入人未满的对局。\n";
//		return;
//	}
//	it_room->nameB = username_player;
//	it_room->people_num++;
//	it_room->portB = portB;
//}