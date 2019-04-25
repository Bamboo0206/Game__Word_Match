#include"header.h"
#include"variable.h"


/************基类*************/
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

 bool participant::operator==(participant const &A)
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
void participant::update_level()
{
	/*等级是EXP的上凸函数，等级越高升级所需增加的经验越多*/
	/*暂时是开根号*/
	/*level=f(EXP)=EXP^(1/2)*/
	level = sqrt(EXP / 100);//会被截断为整数的
	//为什么/100呢，去看宏定义EXP_BASIC_MAKER
}

/****************闯关者*****************/
player::player()
{
	level = 0;
	EXP = 0;
	pass_count = 0;
}

player::player(const player & p1)
{
	name = p1.name;
	level = p1.level;
	EXP = p1.EXP;
	pass_count = p1.pass_count;
}

 player::player(string s)
{
	name = s;
	level = 0;
	EXP = 0;
	pass_count = 0;
}

 player::player(string n, int l, long e, int r)
 {
	 name = n;
	 level = l;
	 EXP = e;
	 pass_count = r;
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
	pass_count = p1.level;
	return *this;
}

void player::update_EXP(int difficulty)
{
	EXP = EXP + EXP_BASIC_MAKER * difficulty;
}


/*****************出题者****************/

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

 test_maker::test_maker(string s)
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
	sort(word_set.begin(), word_set.end());
	vector<string>::iterator it, input_it;
	input_it = find(word_set.begin(), word_set.end(), input_word);

	/*手动求元素序号*/
	int seq = 0;
	for (it = word_set.begin(); it != input_it; it++)
		seq++;
	int size = word_set.size();

	/*分五级，分别加不同经验*/
	if (seq < (size) / 5)//EXP1
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER;
	}
	else if ((size) / 5 <= seq && seq < (size) * 2 / 5)
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER * 2;//二倍基础经验
	}
	else if ((size)*2 / 5 <= seq && seq < (size) * 3 / 5)
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER * 3;
	}
	else if ((size) *3 / 5 <= seq && seq < (size) * 4 / 5)
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER * 4;
	}
	else if ((size)*4 / 5 <= seq && seq < size)
	{
		this->EXP = this->EXP + EXP_BASIC_MAKER * 5;
	}
}


int test_maker::show_word_num()const
{
	return word_num;
}
