#include"header.h"
#include"class.h"

/*全局变量*/ //在main里定义
extern vector<player> v_player;//所有player
extern vector<test_maker> v_test_maker;//所有test_maker
extern vector<player>::iterator it_user_player;//当前系统用户player
extern vector<test_maker>::iterator it_user_test_maker;//当前系统用户test_maker
extern vector<string> word_set;//单词集合