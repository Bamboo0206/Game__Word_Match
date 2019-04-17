#include"header.h"
//
//class participant
//{
//public:
//	participant();
//	~participant();
//	bool operator==(const participant &A);
//
//	//virtual void sign_up() = 0;//注册 //????
//	//void log_in();//登陆
//	//friend bool equal_name(participant &A, string &name);
//protected://为了能被派生类成员函数访问到
//	string name;
//	//要不要password
//	int level;
//	int EXP;//经验值experience point
//};

participant::participant()
{
}

participant::~participant()
{
}

inline bool participant::operator==(participant const &A)
{
	if (A.name == name)
		return true;
	else
		return false;
}

//
///*闯关者*/
//class player :public participant
//{
//public:
//	player();
//	player(string s);
//	~player();
//	//virtual void sign_up() override;//注册
//	//friend bool equal_name(player &A, player &B);
//
//private:
//	int round;//已闯关数量
//};

player::player()
{
}

inline player::player(string s)
{
	name = s;
	level = 0;
	EXP = 0;
	round = 0;
}

player::~player()
{
}

//inline void player::sign_up()
//{
//	cout << "请输入用户名：\n";
//	getline(cin, name);
//	/*待改：输入正确性检验*/
//
//}


///*出题者*/
//class test_maker :public participant
//{
//public:
//	test_maker();
//	test_maker(string s);
//	~test_maker();
//	//friend bool equal_name(test_maker &A, test_maker &B);
//private:
//	int word_num;
//};

test_maker::test_maker()
{
}

inline test_maker::test_maker(string s)
{
	name = s;
	level = 0;
	EXP = 0;
	word_num = 0;
}

test_maker::~test_maker()
{
}
