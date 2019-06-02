#define BUF_SIZE 1024 //�����ַ����Ļ�������С

/*�ṹ��*/
typedef struct {
	SOCKET *skt;
	SOCKADDR_IN *addr;
}SKT_INFO;

//����
class participant
{
public:
	participant();
	participant(const participant &p1);
	participant(const string &name1);
	~participant();

	bool operator==( participant const &A);
	bool operator<(const participant &p1);//�������ֵ���ȴ�С
	participant & operator=(const participant &p1);//��ֵ���������

	string show_name()const { return name; }
	int show_level() const{ return level; }
	long show_EXP() const{ return EXP; }
	void update_level();

	
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
	player(string n,int l,long e,int r);
	~player();

	bool operator<(const player &p1);//�������ֵ���ȴ�С
	player & operator=(const player &p1);//��ֵ���������


	void inc_pass_count(){ ++pass_count; }
	int update_EXP(int difficulty);					//���� ���㾭��ֵ�����Ѷ�
	int update_EXP(double time_consume,int round);	//���� ���㾭��ֵ���ں�ʱ�͹ؿ����
	int show_pass_count()const { return pass_count; }
private:
	int pass_count;//�Ѵ�������
};

/*������*/
class test_maker:public participant
{
public:
	test_maker();
	test_maker(const test_maker &t1);//�������캯��
	test_maker(string s);
	test_maker(string n, int l, long e, int w);
	~test_maker();

	bool operator<(const test_maker &p1);//�������ֵ���ȴ�С
	test_maker & operator=(const test_maker &p1);//��ֵ���������

	void inc_word_num();
	int update_EXP(string word);//����ȼ�EXP����ȼ���

	int show_word_num()const;
private:
	int word_num;
};


/*ϵͳ��Ϣ*/
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
	bool kind;//0�����ߣ�1������
	stringstream oss, iss;//����׼����������󶨵�stringstream��
	SOCKET *sClient;
	SOCKADDR_IN *ClientAddr;
	char sendData[BUF_SIZE];
	char recData[BUF_SIZE];
private:

};

/*˫�˶�ս*/
class room
{
public:
	room();
	room(const room &r);
	room(int roomNum, string nameA);
	~room();

	int roomNumber;
	unsigned short int portA, portB;//�����������
	string nameA, nameB;//����
	double timeA, timeB;//��ʱ
	int winA, winB;//AB����Ӯ�Ĵ���
	char resultA, resultB;//�����ȷ�����
	int word_num_to_pass;
	string word;
	int display_time;
	int people_num;
private:

};


/*������*/
/*�Զ���Ƚϴ�С��ʽ�����ַ������ȱȽϣ������ࣩ*/
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

/*�궨��*/
#define EXP_BASIC_MAKER 100 //�����߳ɹ���һ�����ʵ���;���ֵ
#define DEBUG 1