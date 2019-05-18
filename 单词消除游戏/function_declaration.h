
/*函数*/
void sign_up();
void log_in(string &username_player, string &username_test_maker);
void log_out(string &username_player, string &username_test_maker);
void add_word(string &username_test_maker);
void start_game(string &username_player);
bool cin_error_and_repair();

/*initialize.cpp*/
void read_wordlib();
void read_player();
void read_test_maker();

/*rank*/
void rank_player();
void rank_test_maker();

/*search_participant*/
void search_player();
void search_test_maker();
void my_find(char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input , string name_input );

/*write_file.cpp*/
void write_participants();

/*tool.cpp*/
void print_player(string &username_player);//打印当前登陆的player的用户信息
void print_test_maker(string &username_test_maker);//打印当前登陆的test_maker的用户信息
void locate_player(string name, vector<player>::iterator &it_user_player);//使迭代器指向name的player
void locate_test_maker(string name, vector<test_maker>::iterator &it_user_test_maker);