#define BUF_SIZE 1024 //发送字符串的缓冲区大小

/*结构体*/
typedef struct {
	SOCKET *skt;
	SOCKADDR_IN *addr;
}SKT_INFO;

//基类
class participant
{
public:
	participant();
	participant(const participant &p1);
	participant(const string &name1);
	~participant();

	bool operator==( participant const &A);
	bool operator<(const participant &p1);//按名字字典序比大小
	participant & operator=(const participant &p1);//赋值运算符重载

	string show_name()const { return name; }
	int show_level() const{ return level; }
	long show_EXP() const{ return EXP; }
	void update_level();

	
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

	bool operator<(const player &p1);//按名字字典序比大小
	player & operator=(const player &p1);//赋值运算符重载


	void inc_pass_count(){ ++pass_count; }
	int update_EXP(int difficulty);					//重载 计算经验值基于难度
	int update_EXP(double time_consume,int round);	//重载 计算经验值基于耗时和关卡序号
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

	bool operator<(const test_maker &p1);//按名字字典序比大小
	test_maker & operator=(const test_maker &p1);//赋值运算符重载

	void inc_word_num();
	int update_EXP(string word);//务必先加EXP再算等级！

	int show_word_num()const;
private:
	int word_num;
};


/*系统信息*/
class sysInfo
{
public:
	sysInfo(SKT_INFO *sktInfo);
	sysInfo(const sysInfo &s);
	sysInfo();
	~sysInfo();
	bool operator ==(const sysInfo &s);
	sysInfo& operator=(const sysInfo &s);

	string name;
	bool kind;//0闯关者，1出题者
	stringstream oss, iss;//将标准输入输出流绑定到stringstream上
	SOCKET *sClient;
	SOCKADDR_IN *ClientAddr;
	char sendData[BUF_SIZE];
	char recData[BUF_SIZE];
private:

};

/*双人对战*/
class room
{
public:
	room();
	room(const room &r);
	room(int roomNum, string nameA);
	~room();

	int roomNumber;
	unsigned short int portA, portB;//用于输入输出
	string nameA, nameB;//名字
	double timeA, timeB;//耗时
	int winA, winB;//AB各自赢的次数
	char resultA, resultB;//结果正确或错误
	int word_num_to_pass;
	string word;
	int display_time;
	int people_num;
private:

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

struct name_greater
{
	bool operator()(const participant & a1, const participant & a2) const
	{
		return a1.show_name() > a2.show_name();
	}
};
struct EXP_greater
{
	bool operator()(const participant & a1, const participant & a2) const
	{
		return a1.show_EXP() > a2.show_EXP();
	}
};
struct level_greater
{
	bool operator()(const participant & a1, const participant & a2) const
	{
		return a1.show_level() > a2.show_level();
	}
};
struct pass_count_greater
{
	bool operator()(const player & a1, const player & a2) const
	{
		return a1.show_pass_count() > a2.show_pass_count();
	}
};
struct word_num_greater
{
	bool operator()(const test_maker & a1, const test_maker & a2) const
	{
		return a1.show_word_num() > a2.show_word_num();
	}
};

/*宏定义*/
#define EXP_BASIC_MAKER 100 //出题者成功出一个单词的最低经验值
#define DEBUG 1