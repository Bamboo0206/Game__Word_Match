#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<iterator>
#include<set>
#include<cmath>
using namespace std;

//����
class participant
{
public:
	participant();
	participant(const participant &p1);
	participant(const string &name1);
	~participant();

	bool operator==( participant const &A);
	bool operator<(const participant &p1);//�������ֵ���ȴ�С//???
	participant & operator=(const participant &p1);//��ֵ���������

	string show_name() { return name; }

	//virtual void sign_up() = 0;//ע�� //????
	//void log_in();//��½
	//friend bool equal_name(participant &A, string &name);
protected://Ϊ���ܱ��������Ա�������ʵ�
	string name;
	int level;
	long EXP;//����ֵexperience point
};


/*������*/
class player:public participant
{
public:
	player();
	player(const player &p1);
	player(string s);
	~player();

	bool operator<(const player &p1);//�������ֵ���ȴ�С//???
	player & operator=(const player &p1);//��ֵ���������

	//virtual void sign_up() override;//ע��
	//friend bool equal_name(player &A, player &B);

private:
	int round;//�Ѵ�������
};

/*������*/
class test_maker:public participant
{
public:
	test_maker();
	test_maker(const test_maker &t1);//�������캯��
	test_maker(string s);
	~test_maker();

	bool operator<(const test_maker &p1);//�������ֵ���ȴ�С//???
	test_maker & operator=(const test_maker &p1);//��ֵ���������

	//friend bool equal_name(test_maker &A, test_maker &B);
	void inc_word_num();
	void update_EXP(string word);//����ȼ�EXP����ȼ���
	void update_level();
private:
	int word_num;
};


/*������*/
/*�Զ���Ƚϴ�С��ʽ�����ַ������ȱȽϣ������ࣩ*/
struct shorter
{
	bool operator()(const string & a1, const string & a2)
	{
		return a1.size() < a2.size();
	}
};

/*�궨��*/
#define EXP_BASIC_MAKER 100 //�����߳ɹ���һ�����ʵ���;���ֵ

