/*��ʼ���������ʣ����û�*/

#include"header.h"
#include"variable.h"

void read_wordlib()
{
	fstream f_wordlib("wordlib.csv", ios::in);
	f_wordlib.seekg(0, fstream::beg);
	string word;
	while (!f_wordlib.eof())
	{
		f_wordlib >> word;
		word_set.push_back(word);
	}
}
void read_player()
{
	fstream inFile("player.csv", ios::in);
	if (!inFile) { cerr<<"�޷����ļ�player.csv" << endl; return; }
	inFile.seekg(0, fstream::beg);
	
	while (!inFile.eof())
	{
		int level, pass_count;
		long EXP;
		string name;
		getline(inFile, name, ',');
		cin >> level;
		getchar();
		cin >> EXP;
		getchar();
		cin >> pass_count;
		getchar();
		player temp(name, level, EXP, pass_count);
		v_player.push_back(temp);
	}
}
void read_test_maker()
{

}