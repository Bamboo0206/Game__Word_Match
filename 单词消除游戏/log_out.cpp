#include"header.h"
#include"variable.h"
#include"function_declaration.h"

void log_out(string &username_player, string &username_test_maker, unsigned short int port)
{
	string name, type;
	vector<sysInfo>::iterator it_sysInfo;
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->oss << "请选择登出类型：闯关者player/出题者test_maker：\n";
	mySend(port);
	myRecv(port);
	for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
	it_sysInfo->iss >> type;
	if (type == "player")  
	{
		/*检测是否登陆*/
		if(username_player.empty())
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "请先登陆\n";
			return;
		}
		print_player(username_player,port);
		//it_user_player = v_player.end();
		username_player.resize(0);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "已登出" << endl;
	}
	else if (type == "test_maker")
	{
		/*检测是否登陆*/
		if(username_test_maker.empty())
		{
			for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
			it_sysInfo->oss << "请先登陆\n";
			return;
		}
		print_test_maker(username_test_maker, port);
		username_test_maker.resize(0);
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "已登出" << endl;
	}
	else
	{
		for (it_sysInfo = v_sysInfo.begin(); it_sysInfo != v_sysInfo.end() && it_sysInfo->ClientAddr->sin_port != port; it_sysInfo++);
		it_sysInfo->oss << "不正确的类型\n";
	}
}