#include<iostream>
#include<string>
using namespace std;

//基类
class participant
{
public:
	participant();
	~participant();

private:
	string name;
	int level;
	int EXP;//经验值experience point
};

participant::participant()
{
}

participant::~participant()
{
}

/*闯关者*/
class player:public participant
{
public:
	player();
	~player();

private:
	int round;//已闯关数量
};

player::player()
{
}

player::~player()
{
}


/*出题者*/
class test_maker:public participant
{
public:
	test_maker();
	~test_maker();

private:
	int question_num;
};

test_maker::test_maker()
{
}

test_maker::~test_maker()
{
}