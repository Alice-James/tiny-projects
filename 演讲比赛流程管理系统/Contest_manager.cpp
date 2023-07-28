#include "Contest_manager.h"


Contest_manager::Contest_manager()
{
	//this->player_sum = SUM_ORIGIN;
	ifstream ifs(FILE, ios::in);
	if (ifs.is_open() && !is_empty())
	{
		total_seasons = get_lines();

		string line, item;
		stringstream ss;
		int num;
		double score;
		vector<pair<int, double>> winners_of_the_season;
		for (int i = 0; i < total_seasons; i++)
		{
			getline(ifs, line);
			ss.str(line);

			for (int j = 0; j < SUM_WINNER; j++)
			{
				getline(ss, item, ',');
				num = stoi(item);
				getline(ss, item, ',');
				score = stod(item);
				winners_of_the_season.push_back(make_pair(num, score));
			}
			contest_result.push_back(winners_of_the_season);
			winners_of_the_season.clear();
		}
	}
	else
	{
		total_seasons = 0;
	}
	ifs.close();
}

Contest_manager::~Contest_manager() {}

void Contest_manager::show_menu()
{
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� *************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl << "����������ѡ��" << endl;
}
void Contest_manager::show_menu(int)
{
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� *************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void Contest_manager::quit()
{
	cout << "��ӭ�ٴ�ʹ��" << endl;
	exit(0);
}

void Contest_manager::start_contest()
{
	// 1 ��ʼ������ѡ��
	vector<Player> v;
	for (int i = 0; i < 12; i++)
	{
		v.push_back(Player(10001 + i));
	}


	// 2 ָ����1���ݽ�˳��
	cout << "�� << 1 >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	// 2.1 ����˳��
	random_shuffle(v.begin(), v.end());
	// 2.2 �ֳ�2����
	vector<vector<Player>> group;
	group.reserve(2);
	vector<Player>::const_iterator it = v.begin();
	for (int i = 0; i < 2; i++)
	{
		group.push_back(vector<Player>(it, it + 6));
		it += 6;
	}
	// 2.3 ��ӡ�ݽ�˳��
	cout << "-----------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	for (int i = 0; i < group.size(); i++)
	{
		for (int j = 0; j < group[i].size(); j++)
		{
			cout << group[i][j].get_num();
			if (j != group[i].size() - 1 || i != group.size() - 1) cout << " ";
			else cout << endl;
		}
	}
	cout << "-----------------------------" << endl;
	system("pause");

	// 3 ��1�ֱ���
	cout << "--------------- ��1����ʽ������ʼ ---------------" << endl;
	// 3.1 ���ɱ������
	for (int i = 0; i < group.size(); i++)
	{
		// 3.1.1 ���ɳɼ�
		for (int j = 0; j < group[i].size(); j++)
		{
			group[i][j].fill_score_origin();
			group[i][j].calculate_final_score();
		}
		// 3.1.2 ÿ���鰴�ɼ�����
		sort(group[i].begin(), group[i].end(), My_order());
	}
	// 3.2 ��ӡ�������
	for (int i = 0; i < group.size(); i++)
	{

		cout << "��" << i + 1 << "С��������Σ�" << endl;
		for_each(group[i].begin(), group[i].end(), My_print1);
		cout << endl;
	}
	cout << "--------------- ��1�ֱ������ ---------------" << endl;
	system("pause");

	// 4 ��1�ֽ���ѡ��
	// 4.1 ������ѡ��װ��ͬһ������
	vector<Player> winners_round1;
	winners_round1.reserve(group.size() * 3);
	for (int i = 0; i < group.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			winners_round1.push_back(group[i][j]);
		}
	}
	// 4.3 �Խ�����������
	sort(winners_round1.begin(), winners_round1.end(), My_order());
	// 4.2 ��ӡ����ѡ������
	cout << "--------------- ��1�ֽ���ѡ����Ϣ���£�---------------" << endl;
	for_each(winners_round1.begin(), winners_round1.end(), My_print2);
	cout << endl;
	system("pause");
	system("cls");

	// 5 ָ����2���ݽ�˳��
	show_menu(1);
	cout << "�� << 2 >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	// 5.1 ����˳��
	random_shuffle(winners_round1.begin(), winners_round1.end());
	// 5.2 ��ӡ�ݽ�˳��
	cout << "-----------------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;
	for (int i = 0; i < winners_round1.size(); i++)
	{
		cout << winners_round1[i].get_num();
		if (i != winners_round1.size() - 1) cout << " ";
		else cout << endl;
	}
	cout << "-----------------------------" << endl;
	system("pause");

	// 6 ��2�ֱ���
	cout << "--------------- ��2����ʽ������ʼ ---------------" << endl;
	// 6.1 ���ɱ������
	// 6.1.1 ���ɳɼ�
	for (int i = 0; i < winners_round1.size(); i++)
	{
		winners_round1[i].fill_score_origin();
		winners_round1[i].calculate_final_score();
	}
	// 6.1.2 ���ɼ�����
	sort(winners_round1.begin(), winners_round1.end(), My_order());
	// 6.2 ��ӡ�������
	cout << "��2�ֱ������Σ�" << endl;
	for_each(winners_round1.begin(), winners_round1.end(), My_print1);
	cout << endl;
	cout << "--------------- ��2�ֱ������ ---------------" << endl;
	system("pause");

	// 7 ��2�ֽ���ѡ��
	// 7.1 ������ѡ��װ��ͬһ������
	vector<Player> winners_round2;
	winners_round2.reserve(3);
	for (int i = 0; i < 3; i++)
	{
		winners_round2.push_back(winners_round1[i]);
	}
	// 7.2 �Խ�����������
	sort(winners_round2.begin(), winners_round2.end(), My_order());
	// 7.3 ��ӡ����ѡ������
	cout << "--------------- ��2�ֽ���ѡ����Ϣ���£�---------------" << endl;
	for_each(winners_round2.begin(), winners_round2.end(), My_print2);
	cout << endl;
	system("pause");
	system("cls");

	// 8 ����������
	// 8.1 ���浽�������������
	vector<pair<int, double>> winner;
	for (int i = 0; i < 3; i++)
	{
		winner.push_back(make_pair(winners_round2[i].get_num(), winners_round2[i].get_final_score()));
	}
	contest_result.push_back(winner);
	// 8.2 ���³�Ա����
	total_seasons++;
	// 8.3 ���浽�ļ�
	save();
	show_menu(1);
	cout << "��¼�ѱ���" << endl << "���������ϣ�" << endl;
	system("pause");
	system("cls");
}

bool My_order::operator()(const Player& p1, const Player& p2)
{
	if (p1.get_final_score() == p2.get_final_score())
	{
		return p1.get_num() < p2.get_num();
	}

	return p1.get_final_score() > p2.get_final_score();
}

void My_print1(const Player& p)
{
	cout << "��ţ�" << p.get_num() << "\t������ѡ��" << p.get_name() << "\t�ɼ���" << p.get_final_score() << endl;
}

void My_print2(const Player& p)
{
	cout << "ѡ�ֱ�ţ�" << p.get_num() << "\t������ѡ��" << p.get_name() << "\t�÷֣�" << p.get_final_score() << endl;
}

//void Contest_manager::start_contest1()
//{
//	player_sum = SUM_ORIGIN;
//}
//
//void Contest_manager::start_round(int round)
//{
//	// 1 ��ʼ������ѡ��
//	vector<Player> v;
//	for (int i = 0; i < player_sum; i++)
//	{
//		v.push_back(Player(10001 + i));
//	}
//
//	// 2 ָ���ݽ�˳��
//	cout << "�� << " << round << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
//	// 2.1 ����˳��
//	random_shuffle(v.begin(), v.end());
//	// 2.2 ����
//
//	vector<vector<Player>> group;
//	group.reserve(2);
//	vector<Player>::const_iterator it = v.begin();
//	for (int i = 0; i < 2; i++)
//	{
//		group.push_back(vector<Player>(it, it + 6));
//		it += 6;
//	}
//	// 2.3 ��ӡ�ݽ�˳��
//	cout << "-----------------------------" << endl;
//	cout << "��ǩ���ݽ�˳�����£�" << endl;
//	for (int i = 0; i < group.size(); i++)
//	{
//		for (int j = 0; j < group[i].size(); j++)
//		{
//			cout << group[i][j].get_num();
//			if (j != group[i].size() - 1 || i != group.size() - 1) cout << " ";
//			else cout << endl;
//		}
//	}
//	cout << "-----------------------------" << endl;
//	system("pause");
//
//}

void Contest_manager::save()
{
	ofstream ofs(FILE, ios::out);
	for (vector<vector<pair<int, double>>>::const_iterator it = contest_result.begin(); it != contest_result.end(); it++)
	{
		for (vector<pair<int, double>>::const_iterator it2 = (*it).begin(); it2 != (*it).end(); it2++)
		{
			ofs << (*it2).first << "," << (*it2).second << ",";
		}
		ofs << endl;
	}
	ofs.close();
}

bool Contest_manager::is_empty()
{
	ifstream ifs(FILE, ios::in);
	char c;
	ifs >> c;
	bool result = 0;
	if (ifs.eof())
	{
		result = 1;
	}
	ifs.close();

	return result;
}

int Contest_manager::get_lines()
{
	ifstream ifs(FILE, ios::in);
	if (!ifs.is_open())
	{
		ifs.close();
		return 0;
	}

	int counter = 0;
	string line;
	while (getline(ifs, line))
	{
		counter++;
	}
	ifs.close();

	return counter;
}

void Contest_manager::show_result()
{
	if (total_seasons == 0)
	{
		cout << "��û�б�����¼..." << endl;
	}
	else
	{
		for (int i = 0; i < total_seasons; i++)
		{
			cout << "��" << i + 1 << "��"
				<< "\t�ھ���ţ�" << contest_result[i][0].first << " �÷֣�" << contest_result[i][0].second
				<< "\t�Ǿ���ţ�" << contest_result[i][1].first << " �÷֣�" << contest_result[i][1].second
				<< "\t������ţ�" << contest_result[i][2].first << " �÷֣�" << contest_result[i][2].second
				<< endl;
		}
	}

	system("pause");
	system("cls");
}

void Contest_manager::delete_result()
{
	cout << "ȷ����գ�\n1��ȷ��\n2������" << endl;
	int instruction;
	while (1)
	{
		cin >> instruction;
		if (1 <= instruction && instruction <= 2)
		{
			break;
		}
		else
		{
			cout << "������1~2��" << endl;
		}
	}
	switch (instruction)
	{
	case 1:
	{
		ofstream ofs(FILE, ios::trunc);
		if (!ofs.is_open())
		{
			cout << "�ļ������ڣ�" << endl;
		}
		else
		{
			contest_result.clear();
			total_seasons = 0;
			cout << "��ճɹ���" << endl;
		}
		ofs.close();
		system("pause");
		system("cls");
		
		break;
	}

	case 2:
	{
		system("cls");

		break;
	}
	}
}