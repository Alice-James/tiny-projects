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

	void fill_score_origin();// ��ʼ���

	void calculate_final_score();// �������յ÷�

	int get_num() const;
	string get_name() const;
	double get_final_score() const;

private:

	int num;// ѡ�ֱ��
	string name;// ѡ������
	vector<int> score_origin;// ��ʼ�÷ֱ�
	double final_score;// ���յ÷�
};
