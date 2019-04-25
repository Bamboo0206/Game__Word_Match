#include"header.h"
#include"variable.h"

void write_participants()
{
	/*写player*/
	fstream f_player("player.csv", ios::out);
	vector<player>::iterator it_player;
	for (it_player = v_player.begin();
		it_player != v_player.end();
		it_player++)
	{
		f_player << it_player->show_name() << ','
			<< it_player->show_level() << ','
			<< it_player->show_EXP() << ','
			<< it_player->show_pass_count() << endl;
	}

	/*写test_maker*/
	fstream f_test_maker("test_maker.csv", ios::out);
	vector<test_maker>::iterator it_test_maker;
	for (it_test_maker = v_test_maker.begin();
		it_test_maker != v_test_maker.end();
		it_test_maker++)
	{
		f_test_maker << it_test_maker->show_name() << ','
			<< it_test_maker->show_level() << ','
			<< it_test_maker->show_EXP() << ','
			<< it_test_maker->show_word_num() << endl;
	}
}