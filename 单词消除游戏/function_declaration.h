
/*����*/
void sign_up();
void log_in(vector<player>::iterator &it_user_player, vector<test_maker>::iterator &it_user_test_maker);
void log_out(vector<player>::iterator &it_user_player, vector<test_maker>::iterator &it_user_test_maker);
void add_word(vector<test_maker>::iterator &it_user_test_maker);
void start_game(vector<player>::iterator &it_user_player);
void print_player(vector<player>::iterator &it_user_player);//��ӡ��ǰ��½��player���û���Ϣ
void print_test_maker(vector<test_maker>::iterator &it_user_test_maker);//��ӡ��ǰ��½��test_maker���û���Ϣ
bool cin_error_and_repair();

/*initialize.cpp*/
void read_wordlib();
void read_player();
void read_test_maker();

/*rank*/
void rank_player(vector<player>::iterator &it_user_player);
void rank_test_maker(vector<test_maker>::iterator &it_user_test_maker);

/*search_participant*/
void search_player();
void search_test_maker();
void my_find(char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input , string name_input );

/*write_file.cpp*/
void write_participants();