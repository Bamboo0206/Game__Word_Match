#include"header.h"
extern set<string> word_set;//���ʼ���


//
//class participant
//{
//public:
//	participant();
//	~participant();
//	bool operator==(const participant &A);
//
//	//virtual void sign_up() = 0;//ע�� //????
//	//void log_in();//��½
//	//friend bool equal_name(participant &A, string &name);
//protected://Ϊ���ܱ��������Ա�������ʵ�
//	string name;
//	//Ҫ��Ҫpassword
//	int level;
//	int EXP;//����ֵexperience point
//};

/************����*************/
participant::participant()
{
	level = 0;
	EXP = 0;
}

participant::participant(const participant & p1)
{
	name = p1.name;
	level = p1.level;
	EXP = p1.EXP;
}

participant::participant(const string & name1)
{
	name = name1;
	level = 0;
	EXP = 0;
}

participant::~participant()
{
}

inline bool participant::operator==(participant const &A)
{
	return A.name == name;
}

bool participant::operator<(const participant & p1)
{
	return this->name < p1.name;
}

participant & participant::operator=(const participant & p1)
{
	if (this == &p1) return *this;
	
	name = p1.name;
	EXP = p1.EXP;
	level = p1.level;
	return *this;
}

//
/****************������*****************/
//class player :public participant
//{
//public:
//	player();
//	player(string s);
//	~player();
//	//virtual void sign_up() override;//ע��
//	//friend bool equal_name(player &A, player &B);
//
//private:
//	int round;//�Ѵ�������
//};

player::player()
{
	level = 0;
	EXP = 0;
	round = 0;
}

player::player(const player & p1)
{
	name = p1.name;
	level = p1.level;
	EXP = p1.EXP;
	round = p1.round;
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

bool player::operator<(const player & p1)
{
	return this->name < p1.name;
}

player & player::operator=(const player & p1)
{
	if (this == &p1) return *this;

	name = p1.name;
	EXP = p1.EXP;
	level = p1.level;
	round = p1.level;
	return *this;
}

//inline void player::sign_up()
//{
//	cout << "�������û�����\n";
//	getline(cin, name);
//	/*���ģ�������ȷ�Լ���*/
//
//}



/*****************������****************/
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
	level = 0;
	EXP = 0;
	word_num = 0;
}

test_maker::test_maker(const test_maker & t1)
{
	name = t1.name;
	level = t1.level;
	EXP = t1.EXP;
	word_num = t1.word_num;
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

bool test_maker::operator<(const test_maker & p1)
{
	return this->name < p1.name;
}

test_maker & test_maker::operator=(const test_maker & p1)
{
	if (this == &p1) return *this;

	name = p1.name;
	EXP = p1.EXP;
	level = p1.level;
	word_num = p1.word_num;
	return *this;
}

void test_maker::inc_word_num()
{
	++word_num;
	return;
}

void test_maker::update_EXP(string input_word)
{
	set<string>::iterator it;
	it = word_set.lower_bound(input_word);//��input_word��greatest lower bound ^
	
	/*�ֶ���Ԫ�����*/
	int seq = 0;
	for (it = word_set.begin(); it != word_set.lower_bound(input_word); it++)
		seq++;

	/*���弶���ֱ�Ӳ�ͬ����*/
	if (seq < (word_set.size()) / 5)//EXP1
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER;
	}
	else if ((word_set.size()) / 5 <= seq && seq < (word_set.size()) * 2 / 5)
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER * 2;//������������
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
void test_maker::update_level()
{
	/*�ȼ���EXP����͹�������ȼ�Խ�������������ӵľ���Խ��*/
	/*��ʱ�ǿ�����*/
	/*level=f(EXP)=EXP^(1/2)*/
	level = sqrt(EXP / 100);//�ᱻ�ض�Ϊ������
	//Ϊʲô/100�أ�ȥ���궨��EXP_BASIC_MAKER
}
