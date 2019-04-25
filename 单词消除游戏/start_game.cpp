#include"header.h"
#include"variable.h"

/*游戏每一关，程序会根据该关卡难度，显示一个单词，一定时间后单词消失。
闯关者需要在相应地方输入刚刚显示并消失的单词，如果闯关者输入正确则为通过。*/

void start_game()
{
	bool finish = false;
	//pair<set<string>::iterator, bool> insert_result;//使用pair！
	string input_word;
	//set<string>::iterator word_it = word_set.begin();
	int difficulty = 1, size = 0;

	size = word_set.size();
	if (!size) { cout << "词库为空！请先添加单词\n"; return ; }

	sort(word_set.begin(), word_set.end(),my_shorter());

	while (!finish)
	{
		cout << "请选择难度（1-5）：" << endl;
		cin >> difficulty;
		/*待加入：正确性检验 若有空格之类的会导致fail*/
		cout << "请记住这个单词（3s后消失）：" ;

		int loc = 0;//下标
		loc = rand() % (size / 5);
		switch (difficulty)
		{
		case 1://随机取前1/5单词
			//loc = rand() % (size / 5);//可能会出现%不起作用的问题
			break;
		case 2:
			loc+=size * 1 / 5;//可能会出现%不起作用的问题
			break;
		case 3:
			loc += size * 2 / 5;
			//loc = rand() % (size *  2/ 5);//可能会出现%不起作用的问题
			break;
		case 4:
			loc += size * 3 / 5;
			//loc = rand() % (size * 3/ 5);//可能会出现%不起作用的问题
			break;
		case 5:
			loc += size * 4 / 5;
			//loc = rand() % size;//可能会出现%不起作用的问题
			break;
		case 0:
			cout << "游戏已退出" << endl;
			return;
		default:
			break;
		}
		cout << word_set.at(loc);
		Sleep(3000);

		cout << "\r                                                            ";
		cout<<"\r请输入刚才出现的单词：";
		cin >> input_word;
		/*待改 正确性检验*/

		if (input_word == word_set.at(loc))//正确
		{
			cout << "输入单词正确，闯关成功\n";
			/*更新等级、经验*/

		}
		else//错误
		{
			cout << "输入单词错误，闯关失败\n";
		}
		cout << "输入0退出游戏\n";
	}
}