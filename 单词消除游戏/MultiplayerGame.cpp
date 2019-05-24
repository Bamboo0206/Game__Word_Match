#include"header.h"
#include"variable.h"
#include"function_declaration.h"

/*创建一个房间并等待*/
void newRoom(string &username_player,int roomNumber,  unsigned short int portA)
{
	vector<sysInfo>::iterator it_sysInfo;
	for (vector<room>::iterator it_room = v_room.begin(); it_room != v_room.end() ; it_room++)
	{
		if (it_room->roomNumber == roomNumber)
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
			it_sysInfo->oss << "该房号已存在。请选择其他房间号。\n";
			return;
		}
	}

	/*创建房间*/
	{
		room r(roomNumber, username_player);
		r.portA = portA;
		v_room.push_back(r);//会用到拷贝构造函数
	}

	int difficulty;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << "请选择难度（1~5）：\n";
	mySend(portA);
	myRecv(portA);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->iss >> difficulty;
	if(difficulty<1|| difficulty>5)
		difficulty = difficulty % 5 + 1;//排除错误输入

	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << "成功创建对局。\n等待对手加入...\n";
	mySend(portA);

	/*等待一个人加入该房间*/
	vector<room>::iterator it_room;
	while (true)
	{
		for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);//将iterator定位到该房号的房间
		if (it_room->people_num == 2)
			break;
		else
			Sleep(200);
	}

	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << "已找到对手。\n等待开局...\n\0";
	mySend(portA);

	/*开始游戏*/

	/*计算单词长度（5级），单词个数，显示时间*/

	int round_current = difficulty * 2;
	it_room->word_num_to_pass = sqrt(round_current);
	it_room->display_time = -round_current * 2000 / 15 + 3000;
	it_room->display_time = it_room->display_time > 1000 ? it_room->display_time : 1000;//下限1000
	//it_room->error_chance = -round_current * 2 / 15 + 3;
	//it_room->error_chance = it_room->error_chance > 1 ? it_room->error_chance : 1;//下限1
		/*输出*/
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << "*******************************************************************************************\n"
		<< "\t玩家A：" << it_room->nameA << "\tVs.\t玩家B：" << it_room->nameB << endl
		<< "                  难度：" << difficulty << "级\n"
		<< "单词：" << it_room->word_num_to_pass << "个，显示时间：" << it_room->display_time << "毫秒" << endl
		<< "*******************************************************************************************\n";
	mySend(portA);

	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
	it_sysInfo->oss << "*******************************************************************************************\n"
		<< "\t玩家A：" << it_room->nameA << "\tVs.\t玩家B：" << it_room->nameB<<endl
		<< "                  难度：" << difficulty << "级\n"
		<< "单词：" << it_room->word_num_to_pass << "个，显示时间：" << it_room->display_time << "毫秒" << endl
		<< "*******************************************************************************************\n";
	mySend(it_room->portB);

	Sleep(50);

	int loc = 0, wordlib_size = 0, word_passed = 0;//下标,单词数量,已通过数量
	wordlib_size = word_set.size();

	/*输出word_num_to_pass 和 display_time*/
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
	it_sysInfo->oss << it_room->word_num_to_pass << " " << it_room->display_time << "\n\0";
	mySend(portA);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
	it_sysInfo->oss << it_room->word_num_to_pass << " " << it_room->display_time << "\n\0";
	mySend(it_room->portB);
	Sleep(50);

	
	while ((it_room->word_num_to_pass )--)
	{
		/*计算单词下标*/
		loc = rand() % (wordlib_size / 5);
		switch (difficulty)
		{
		case 1://随机取前1/5单词
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
		/*发送单词*/
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->oss /*<< it_room->display_time << " " */<< word_set.at(loc)<<"\0";
		mySend(portA);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
		it_sysInfo->oss /*<< it_room->display_time << " " */<< word_set.at(loc) << "\0";
		mySend(it_room->portB);

		/*接收结果*/
		//char resultA,resultB;//结果
		//double tempDA, tempDB;
		myRecv(portA);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->iss >> it_room->resultA >> it_room->timeA;
		myRecv(it_room->portB);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->iss >> it_room->resultB >> it_room->timeB;

		//it_room->timeA += tempDA;//算时间;
		//it_room->timeB += tempDB;
		//it_room->resultA = resultA;
		//it_room->resultB = resultB;

		/*判断*/
		if (it_room->resultA&&it_room->resultB)//AB都对比时间
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
		else//正确的win++
		{
			if(it_room->resultA)
				it_room->winA++;
			else if (it_room->resultB)
				it_room->winB++;
		}
	}
	/*更新等级、经验*/
	if (it_room->winA > it_room->winB)
	{
		vector<player>::iterator it_user_player;
		locate_player(it_room->nameA, it_user_player);
		it_user_player->inc_pass_count();
		int expA = it_user_player->update_EXP(difficulty);
		it_user_player->update_level();

		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->oss << "玩家A胜利，B失败\n"
			<< it_room->nameA <<" : EXP+" << expA << endl;

		print_player(it_room->nameA, portA);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
		it_sysInfo->oss << "玩家A胜利，B失败\n"
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
		it_sysInfo->oss << "玩家B胜利，A失败\n"
			<< it_room->nameB << " : EXP+" << expB << endl;
		print_player(it_room->nameA, portA);
		
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
		it_sysInfo->oss << "玩家B胜利，A失败\n"
			<< it_room->nameB << " : EXP+" << expB << endl;
		print_player(it_room->nameB, it_room->portB);
	}
	else
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portA; it_sysInfo++);
		it_sysInfo->oss << "平局\n";
		print_player(it_room->nameA, portA);

		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != it_room->portB; it_sysInfo++);
		it_sysInfo->oss << "平局\n";
		print_player(it_room->nameB, it_room->portB);
	}

	/*删除该房间*/
	it_room->people_num = 0;
	it_room->roomNumber = -1;
	return;
}


/*加入一个房间并开始游戏*/
void joinRoom(string &username_player, int roomNumber, unsigned short int portB)
{
	vector<sysInfo>::iterator it_sysInfo;
	vector<room>::iterator it_room;
	for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);//将iterator定位到该房号的房间
	if (it_room == v_room.end())
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portB; it_sysInfo++);
		it_sysInfo->oss << "该对局不存在。请创建对局或加入已存在的对局。\n";
		return;
	}
	if (it_room->people_num == 2)
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portB; it_sysInfo++);
		it_sysInfo->oss << "该对局人已满。请创建对局或加入人未满的对局。\n";
		return;
	}
	it_room->nameB = username_player;
	it_room->people_num++;
	it_room->portB = portB;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != portB; it_sysInfo++);
	it_sysInfo->oss << "已找到对手。\n等待开局...\n\0";
	mySend(portB);
	while (it_room->people_num!=0)//等待对局结束
	{
		Sleep(2000);
		for (it_room = v_room.begin(); it_room != v_room.end() && it_room->roomNumber != roomNumber; it_room++);
	}
}