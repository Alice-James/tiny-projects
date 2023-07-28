#pragma once
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>


class Player
{
public:

	Player();
	Player(int num);

	~Player();

	void fill_score_origin();// 初始打分

	void calculate_final_score();// 计算最终得分

	int get_num() const;
	string get_name() const;
	double get_final_score() const;

private:

	int num;// 选手编号
	string name;// 选手姓名
	vector<int> score_origin;// 初始得分表
	double final_score;// 最终得分
};
