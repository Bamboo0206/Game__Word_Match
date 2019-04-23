#include"header.h"
extern set<string> word_set;//单词集合


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

/************基类*************/
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
/****************闯关者*****************/
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

void test_maker::update_level()
{
	/*下凸函数？？？*/
}


/*****************出题者****************/
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

void test_maker::inc_word_num()
{
	++word_num;
	return;
}

void test_maker::update_EXP(string input_word)
{
	set<string>::iterator it;
	it = word_set.lower_bound(input_word);//找input_word的greatest lower bound ^
	
	/*手动求元素序号*/
	int seq = 0;
	for (it = word_set.begin(); it != word_set.lower_bound(input_word); it++)
		seq++;

	/*分五级，分别加不同经验*/
	if (seq < (word_set.size()) / 5)//EXP1
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER;
	}
	else if ((word_set.size()) / 5 <= seq && seq < (word_set.size()) * 2 / 5)
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER * 2;//二倍基础经验
	}
	else if ((word_set.size())*2 / 5 <= seq && seq < (word_set.size()) * 3 / 5)
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER * 3;
	}
	else if ((word_set.size()) *3 / 5 <= seq && seq < (word_set.size()) * 4 / 5)
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER * 4;
	}
	else if ((word_set.size())*4 / 5 <= seq && seq < word_set.size())
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER * 5;
	}
}
