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
				cout << "������0~7�е�һ������" << endl;
			}
		}
		switch (instruction)
		{
		case 0:// �˳��������
		{
			wm.quit_worker_manager();
			break;
		}

		case 1:// ���ְ��
		{
			wm.add_worker();
			break;
		}

		case 2:// ��ʾְ��
		{
			wm.show_worker_all();
			break;
		}

		case 3:// ɾ��ְ��
		{
			wm.delete_worker_by_ID();
			break;
		}

		case 4:// �޸�ְ����Ϣ
		{
			wm.modify_worker_by_ID();
			break;
		}

		case 5:// ����ְ����Ϣ
		{
			wm.search_worker();
			break;
		}

		case 6:// ���ձ������
		{
			wm.sort_worker();
			break;
		}

		case 7:// ��������ĵ�
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