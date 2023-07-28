#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "Player.h"
#include <fstream>
#include <sstream>

#define SUM_ORIGIN 12// 第1轮参赛人数
#define SUM_WINNER 3// 最终获奖人数
#define FILE "speech.csv"// 记录文件路径


class Contest_manager
{
public:

	Contest_manager();

	~Contest_manager();

	void show_menu();// 展示主菜单页面
	void show_menu(int);// 展示主菜单页面(不提示输入)

	void quit();// 退出比赛程序

	bool is_empty();// 判断文件是否为空

	int get_lines();// 返回文件行数

	void save();// 将比赛结果记录到文件中
	
	void start_contest();// 开始演讲比赛
	//void start_contest1();// 开始演讲比赛
	//void start_round(int round);// 开始一轮比赛

	void show_result();// 查看往届记录

	void delete_result();// 清空比赛记录


private:

	int total_seasons;// 比赛一共举办了多少届
	vector<vector<pair<int, double>>> contest_result;// 记录各届比赛结果
	//int player_sum;// 参赛人员数量
};

class My_order// 成绩排序
{
public:

	bool operator()(const Player& p1, const Player& p2);
};

void My_print1(const Player& p);// 打印Player, 方式1
void My_print2(const Player& p);// 打印Player, 方式2
