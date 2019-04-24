/*初始化：读单词，读用户*/

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
void read_