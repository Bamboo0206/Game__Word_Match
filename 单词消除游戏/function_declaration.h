
/*����*/
void sign_up();
void log_in();
void log_out();
void add_word();
void start_game();
void print_player();//��ӡ��ǰ��½��player���û���Ϣ
void print_test_maker();//��ӡ��ǰ��½��test_maker���û���Ϣ
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
//void my_find(char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input = 0, string name_input = NULL);

/*write_file.cpp*/
void write_participants();