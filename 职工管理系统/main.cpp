#include <iostream>
using namespace std;
#include "WorkerManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"


int main()
{
	WorkerManager wm;
	int instruction = 0;
	while (1)
	{
		wm.show_menu();
		while (1)
		{
			cin >> instruction;
			if (0 <= instruction && instruction <= 7)
			{
				break;
			}
			else
			{
				cout << "请输入0~7中的一个数：" << endl;
			}
		}
		switch (instruction)
		{
		case 0:// 退出管理程序
		{
			wm.quit_worker_manager();
			break;
		}

		case 1:// 添加职工
		{
			wm.add_worker();
			break;
		}

		case 2:// 显示职工
		{
			wm.show_worker_all();
			break;
		}

		case 3:// 删除职工
		{
			wm.delete_worker_by_ID();
			break;
		}

		case 4:// 修改职工信息
		{
			wm.modify_worker_by_ID();
			break;
		}

		case 5:// 查找职工信息
		{
			wm.search_worker();
			break;
		}

		case 6:// 按照编号排序
		{
			wm.sort_worker();
			break;
		}

		case 7:// 清空所有文档
		{
			wm.delete_worker_all();
			break;
		}

		default:
		{
			break;
		}
		}

		system("pause");
		system("cls");
	}

	return 0;
}