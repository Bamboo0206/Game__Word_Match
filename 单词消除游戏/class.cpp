#include"header.h"
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
///*������*/
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
//	cout << "�������û�����\n";
//	getline(cin, name);
//	/*���ģ�������ȷ�Լ���*/
//
//}


///*������*/
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
