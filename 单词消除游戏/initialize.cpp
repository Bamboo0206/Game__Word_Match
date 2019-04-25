/*初始化：读单词，读用户*/

#include"header.h"
#include"variable.h"

void read_wordlib()
{
	fstream f_wordlib("wordlib.csv", ios::in);
	if (!f_wordlib) { cerr << "无法打开文件wordlib.csv" << endl; return; }
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
	if (!inFile) { cerr<<"无法打开文件player.csv" << endl; return; }
	inFile.seekg(0, fstream::beg);
	
	string str;
	while (getline(inFile, str))
	{
		int level, pass_count;
		long EXP;
		string name,buf;
		char ch;

		stringstream ss(str);

		getline(ss, name, ',');
		ss >> level;
		getline(ss, buf, ',');
		//inFile >> ch;
		ss >> EXP;
		getline(ss, buf, ',');
		ss >> pass_count;
		getline(ss, buf);//最后是回车

		player temp(name, level, EXP, pass_count);
		v_player.push_back(temp);
	}
}
void read_test_maker()
{

}