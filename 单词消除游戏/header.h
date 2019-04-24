#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<cmath>
using namespace std;

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

	string show_name() { return name; }

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
	~player();

	bool operator<(const player &p1);//按名字字典序比大小//???
	player & operator=(const player &p1);//赋值运算符重载

	//virtual void sign_up() override;//注册
	//friend bool equal_name(player &A, player &B);

private:
	int round;//已闯关数量
};

/*出题者*/
class test_maker:public participant
{
public:
	test_maker();
	test_maker(const test_maker &t1);//拷贝构造函数
	test_maker(string s);
	~test_maker();

	bool operator<(const test_maker &p1);//按名字字典序比大小//???
	test_maker & operator=(const test_maker &p1);//赋值运算符重载

	//friend bool equal_name(test_maker &A, test_maker &B);
	void inc_word_num();
	void update_EXP(string word);//务必先加EXP再算等级！
	void update_level();
private:
	int word_num;
};


/*函数类*/
/*自定义比较大小方式：按字符串长度比较（函数类）*/
struct shorter
{
	bool operator()(const string & a1, const string & a2)
	{
		return a1.size() < a2.size();
	}
};

/*宏定义*/
#define EXP_BASIC_MAKER 100 //出题者成功出一个单词的最低经验值

