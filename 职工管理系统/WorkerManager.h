#pragma once
#include <iostream>
using namespace std;
#include <string>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include <fstream>

#define WORKER_FILE "workers.txt"


// ְ������ϵͳ��
class WorkerManager
{
public:

	WorkerManager();

	~WorkerManager();

	void show_menu();// չʾ���˵�ҳ��

	void quit_worker_manager();// �˳��������

	void add_worker();// ���ְ��

	void save();// ��ȫ��ְ����Ϣ�������ļ���

	bool file_is_empty();// ���ְ����Ϣ�ļ��Ƿ񲻴��ڻ�Ϊ��

	int get_worker_sum();// ��ȡְ����Ϣ�ļ�������ְ������

	void initialize_worker_array();// ��ȡְ����Ϣ�ļ�����ʼ��worker_array

	void show_worker_all();// ��ʾ����ְ����Ϣ

	void delete_worker_by_ID();// ɾ��ָ����ŵ�ְ��

	void modify_worker_by_ID();// �޸�ָ����ŵ�ְ����Ϣ

	void search_worker();// ����ְ����Ϣ
	int search_worker(int src_ID);// ����ָ����ŵ�ְ���������ҵ�����������worker_array�е���ţ����򷵻�-1
	int search_worker(string src_name);// ����ָ��������ְ���������ҵ�����������worker_array�е���ţ����򷵻�-1

	void sort_worker();// ���ձ������
	void sort_worker(int instruction);// ���ձ�����򡣲���Ϊ1��ʾ���򣬲���Ϊ2��ʾ����

	void delete_worker_all();// ɾ������ְ����Ϣ������ļ�


private:

	int worker_sum;// ��¼ְ������

	Worker** worker_array;// ��¼ȫ��ְ����Ϣ�����飬���ÿ��worker�����ָ��
};