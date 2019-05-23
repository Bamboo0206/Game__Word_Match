
/*函数*/
void sign_up(unsigned short int port);
void log_in(string &username_player, string &username_test_maker,unsigned short int port);
void log_out(string &username_player, string &username_test_maker, unsigned short int port);
void add_word(string &username_test_maker, unsigned short int port);
void start_game(string &username_player, unsigned short int port);
bool one_round(string name, unsigned short int port);

/*initialize.cpp*/
void read_wordlib();
void read_player();
void read_test_maker();

/*rank*/
void rank_player(unsigned short int port);
void rank_test_maker(unsigned short int port);

/*search_participant*/
void search_player(unsigned short int port);
void search_test_maker(unsigned short int port);
void my_find(unsigned short int port, char kind/*p/t*/, char qaulity/*n,l,e,p,w*/, long num_input , string name_input );

/*write_file.cpp*/
void write_participants();

/*tool.cpp*/
void print_player(string &username_player, unsigned short int port);//打印当前登陆的player的用户信息
void print_test_maker(string &username_test_maker, unsigned short int port);//打印当前登陆的test_maker的用户信息
void locate_player(string name, vector<player>::iterator &it_user_player);//使迭代器指向name的player
void locate_test_maker(string name, vector<test_maker>::iterator &it_user_test_maker);
bool cin_error_and_repair();
void mySend(char flag/*0为client继续接收*/, unsigned short int port);//flag0为client继续接收，1为client发送
void mySend(unsigned short int port);
void myRecv(unsigned short int port);

/* MultiplayerGame.cpp */
void newRoom(string &username_player, int roomNumber, unsigned short int portA);
void joinRoom(string &username_player, int roomNumber, unsigned short int portB);