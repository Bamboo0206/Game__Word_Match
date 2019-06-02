#include"header.h"
#include"class.h"

/*全局变量*/ //在main里定义
extern vector<player> v_player;//所有player
extern vector<test_maker> v_test_maker;//所有test_maker
extern vector<string> word_set;//单词集合
extern vector<sysInfo> v_sysInfo;//每个线程一个对象，用于存储系统信息和当前系统用户等
extern vector<room> v_room;//游戏房间集合