#include<iostream>
#include<string>
using namespace std;

//����
class participant
{
public:
	participant();
	~participant();

private:
	string name;
	int level;
	int EXP;//����ֵexperience point
};

participant::participant()
{
}

participant::~participant()
{
}

/*������*/
class player:public participant
{
public:
	player();
	~player();

private:
	int round;//�Ѵ�������
};

player::player()
{
}

player::~player()
{
}


/*������*/
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