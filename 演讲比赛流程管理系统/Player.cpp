#include "Player.h"


Player::Player() {}
Player::Player(int num)
{
	string name_seed = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	this->num = num;
	this->name = name_seed[num - 10001];
	this->final_score = 0;
}

Player::~Player() {}

void Player::fill_score_origin()
{
	score_origin.resize(10);// 清空初始打分表
	for (int i = 0; i < 10; i++)
	{
		score_origin[i] = rand() % 41 + 60;
	}
}

void Player::calculate_final_score()
{
	int sum = accumulate(score_origin.begin(), score_origin.end(), 0);
	int max = *(max_element(score_origin.begin(), score_origin.end()));
	int min = *(min_element(score_origin.begin(), score_origin.end()));
	sum -= max + min;
	final_score = (double)sum / (score_origin.size() - 2);
}

int Player::get_num() const
{
	return num;
}
string Player::get_name() const
{
	return name;
}
double Player::get_final_score() const
{
	return final_score;
}
