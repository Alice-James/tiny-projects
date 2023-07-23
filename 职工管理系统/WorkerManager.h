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


// 职工管理系统类
class WorkerManager
{
public:

	WorkerManager();

	~WorkerManager();

	void show_menu();// 展示主菜单页面

	void quit_worker_manager();// 退出管理程序

	void add_worker();// 添加职工

	void save();// 将全体职工信息保存在文件中

	bool file_is_empty();// 检查职工信息文件是否不存在或为空

	int get_worker_sum();// 读取职工信息文件，返回职工总数

	void initialize_worker_array();// 读取职工信息文件，初始化worker_array

	void show_worker_all();// 显示所有职工信息

	void delete_worker_by_ID();// 删除指定编号的职工

	void modify_worker_by_ID();// 修改指定编号的职工信息

	void search_worker();// 查找职工信息
	int search_worker(int src_ID);// 查找指定编号的职工。若能找到，返回其在worker_array中的序号；否则返回-1
	int search_worker(string src_name);// 查找指定姓名的职工。若能找到，返回其在worker_array中的序号；否则返回-1

	void sort_worker();// 按照编号排序
	void sort_worker(int instruction);// 按照编号排序。参数为1表示升序，参数为2表示降序

	void delete_worker_all();// 删除所有职工信息并清空文件


private:

	int worker_sum;// 记录职工总数

	Worker** worker_array;// 记录全体职工信息的数组，存放每个worker对象的指针
};