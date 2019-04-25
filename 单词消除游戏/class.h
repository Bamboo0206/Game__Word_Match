//基类
class participant
{
public:
	participant();
	participant(const participant &p1);
	participant(const string &name1);
	~participant();

	bool operator==( participant const &A);
	bool operator<(const participant &p1);//按名字字典序比大小//???
	participant & operator=(const participant &p1);//赋值运算符重载

	string show_name()const { return name; }
	int show_level() const{ return level; }
	long show_EXP() const{ return EXP; }
	void update_level();

	//void set_name(string n){  name=n; }
	//void set_level(int n) { level=n; }
	//void set_EXP(long n) {  EXP=n; }

	//virtual void sign_up() = 0;//注册 //????
	//void log_in();//登陆
	//friend bool equal_name(participant &A, string &name);
protected://为了能被派生类成员函数访问到
	string name;
	int level;
	long EXP;//经验值experience point
};


/*闯关者*/
class player:public participant
{
public:
	player();
	player(const player &p1);
	player(string s);
	player(string n,int l,long e,int r);
	~player();

	bool operator<(const player &p1);//按名字字典序比大小//???
	player & operator=(const player &p1);//赋值运算符重载


	//virtual void sign_up() override;//注册
	//friend bool equal_name(player &A, player &B);
	void inc_pass_count(){ ++pass_count; }
	void update_EXP(int difficulty);//务必先加EXP再算等级！
	int show_pass_count()const { return pass_count; }
private:
	int pass_count;//已闯关数量
};

/*出题者*/
class test_maker:public participant
{
public:
	test_maker();
	test_maker(const test_maker &t1);//拷贝构造函数
	test_maker(string s);
	test_maker(string n, int l, long e, int w);
	~test_maker();

	bool operator<(const test_maker &p1);//按名字字典序比大小//???
	test_maker & operator=(const test_maker &p1);//赋值运算符重载

	//friend bool equal_name(test_maker &A, test_maker &B);
	void inc_word_num();
	void update_EXP(string word);//务必先加EXP再算等级！

	int show_word_num()const;
private:
	int word_num;
};


/*函数类*/
/*自定义比较大小方式：按字符串长度比较（函数类）*/
struct my_shorter
{
	bool operator()(const string & a1, const string & a2) const
	{
		return a1.size() < a2.size();
	}
};

struct name_less
{
	bool operator()(const participant & a1, const participant & a2) const
	{
		return a1.show_name() < a2.show_name();
	}
};
struct EXP_less
{
	bool operator()(const participant & a1, const participant & a2) const
	{
		return a1.show_EXP() < a2.show_EXP();
	}
};
struct level_less
{
	bool operator()(const participant & a1, const participant & a2) const
	{
		return a1.show_level() < a2.show_level();
	}
};
struct pass_count_less
{
	bool operator()(const player & a1, const player & a2) const
	{
		return a1.show_pass_count() < a2.show_pass_count();
	}
};
class word_num_less
{
	bool operator()(const test_maker & a1, const test_maker & a2) const
	{
		return a1.show_word_num() < a2.show_word_num();
	}
};

/*宏定义*/
#define EXP_BASIC_MAKER 100 //出题者成功出一个单词的最低经验值

