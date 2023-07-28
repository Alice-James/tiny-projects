#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include "Player.h"
#include <fstream>
#include <sstream>

#define SUM_ORIGIN 12// ��1�ֲ�������
#define SUM_WINNER 3// ���ջ�����
#define FILE "speech.csv"// ��¼�ļ�·��


class Contest_manager
{
public:

	Contest_manager();

	~Contest_manager();

	void show_menu();// չʾ���˵�ҳ��
	void show_menu(int);// չʾ���˵�ҳ��(����ʾ����)

	void quit();// �˳���������

	bool is_empty();// �ж��ļ��Ƿ�Ϊ��

	int get_lines();// �����ļ�����

	void save();// �����������¼���ļ���
	
	void start_contest();// ��ʼ�ݽ�����
	//void start_contest1();// ��ʼ�ݽ�����
	//void start_round(int round);// ��ʼһ�ֱ���

	void show_result();// �鿴�����¼

	void delete_result();// ��ձ�����¼


private:

	int total_seasons;// ����һ���ٰ��˶��ٽ�
	vector<vector<pair<int, double>>> contest_result;// ��¼����������
	//int player_sum;// ������Ա����
};

class My_order// �ɼ�����
{
public:

	bool operator()(const Player& p1, const Player& p2);
};

void My_print1(const Player& p);// ��ӡPlayer, ��ʽ1
void My_print2(const Player& p);// ��ӡPlayer, ��ʽ2
