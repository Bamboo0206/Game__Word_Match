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
	~participant();
	bool operator==( participant const &A);
	string show_name() { return name; }

	//virtual void sign_up() = 0;//ע�� //????
	//void log_in();//��½
	//friend bool equal_name(participant &A, string &name);
protected://Ϊ���ܱ��������Ա�������ʵ�
	string name;
	//Ҫ��Ҫpassword
	int level;
	long EXP;//����ֵexperience point
};
//
//participant::participant()
//{
//}
//
//participant::~participant()
//{
//}
//
//inline bool participant::operator==(const participant & A)
//{
//	if (A.name == name)
//		return true;
//	else
//		return false;
//}
//
//
/*������*/
class player:public participant
{
public:
	player();
	player(string s);
	~player();
	//virtual void sign_up() override;//ע��
	//friend bool equal_name(player &A, player &B);

private:
	int round;//�Ѵ�������
};
//
//player::player()
//{
//}
//
//inline player::player(string s)
//{
//	name = s;
//	level = 0;
//	EXP = 0;
//	round = 0;
//}
//
//player::~player()
//{
//}
//
////inline void player::sign_up()
////{
////	cout << "�������û�����\n";
////	getline(cin, name);
////	/*���ģ�������ȷ�Լ���*/
////
////}
//
//
/*������*/
class test_maker:public participant
{
public:
	test_maker();
	test_maker(string s);
	~test_maker();
	//friend bool equal_name(test_maker &A, test_maker &B);
	void inc_word_num();
	void update_EXP(string word);//����ȼ�EXP����ȼ���
	void update_level();
private:
	int word_num;
};
//
//test_maker::test_maker()
//{
//}
//
//inline test_maker::test_maker(string s)
//{
//	name = s;
//	level = 0;
//	EXP = 0;
//	word_num = 0;
//}
//
//test_maker::~test_maker()
//{
//}

/*�궨��*/
#define EXP_BASIC_MAKER 100 //�����߳ɹ���һ�����ʵ���;���ֵ