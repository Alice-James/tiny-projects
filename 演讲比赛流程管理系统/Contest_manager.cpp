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
	cout << "************* 欢迎参加演讲比赛 *************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl << "请输入您的选择：" << endl;
}
void Contest_manager::show_menu(int)
{
	cout << "********************************************" << endl;
	cout << "************* 欢迎参加演讲比赛 *************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void Contest_manager::quit()
{
	cout << "欢迎再次使用" << endl;
	exit(0);
}

void Contest_manager::start_contest()
{
	// 1 初始化比赛选手
	vector<Player> v;
	for (int i = 0; i < 12; i++)
	{
		v.push_back(Player(10001 + i));
	}


	// 2 指定第1轮演讲顺序
	cout << "第 << 1 >> 轮比赛选手正在抽签" << endl;
	// 2.1 打乱顺序
	random_shuffle(v.begin(), v.end());
	// 2.2 分成2个组
	vector<vector<Player>> group;
	group.reserve(2);
	vector<Player>::const_iterator it = v.begin();
	for (int i = 0; i < 2; i++)
	{
		group.push_back(vector<Player>(it, it + 6));
		it += 6;
	}
	// 2.3 打印演讲顺序
	cout << "-----------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
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

	// 3 第1轮比赛
	cout << "--------------- 第1轮正式比赛开始 ---------------" << endl;
	// 3.1 生成比赛结果
	for (int i = 0; i < group.size(); i++)
	{
		// 3.1.1 生成成绩
		for (int j = 0; j < group[i].size(); j++)
		{
			group[i][j].fill_score_origin();
			group[i][j].calculate_final_score();
		}
		// 3.1.2 每个组按成绩排序
		sort(group[i].begin(), group[i].end(), My_order());
	}
	// 3.2 打印比赛结果
	for (int i = 0; i < group.size(); i++)
	{

		cout << "第" << i + 1 << "小组比赛名次：" << endl;
		for_each(group[i].begin(), group[i].end(), My_print1);
		cout << endl;
	}
	cout << "--------------- 第1轮比赛完毕 ---------------" << endl;
	system("pause");

	// 4 第1轮晋级选手
	// 4.1 将晋级选手装入同一个数组
	vector<Player> winners_round1;
	winners_round1.reserve(group.size() * 3);
	for (int i = 0; i < group.size(); i++)
	{
		for (int j = 0; j < 3; j++)
		{
			winners_round1.push_back(group[i][j]);
		}
	}
	// 4.3 对晋级名单排序
	sort(winners_round1.begin(), winners_round1.end(), My_order());
	// 4.2 打印晋级选手名单
	cout << "--------------- 第1轮晋级选手信息如下：---------------" << endl;
	for_each(winners_round1.begin(), winners_round1.end(), My_print2);
	cout << endl;
	system("pause");
	system("cls");

	// 5 指定第2轮演讲顺序
	show_menu(1);
	cout << "第 << 2 >> 轮比赛选手正在抽签" << endl;
	// 5.1 打乱顺序
	random_shuffle(winners_round1.begin(), winners_round1.end());
	// 5.2 打印演讲顺序
	cout << "-----------------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;
	for (int i = 0; i < winners_round1.size(); i++)
	{
		cout << winners_round1[i].get_num();
		if (i != winners_round1.size() - 1) cout << " ";
		else cout << endl;
	}
	cout << "-----------------------------" << endl;
	system("pause");

	// 6 第2轮比赛
	cout << "--------------- 第2轮正式比赛开始 ---------------" << endl;
	// 6.1 生成比赛结果
	// 6.1.1 生成成绩
	for (int i = 0; i < winners_round1.size(); i++)
	{
		winners_round1[i].fill_score_origin();
		winners_round1[i].calculate_final_score();
	}
	// 6.1.2 按成绩排序
	sort(winners_round1.begin(), winners_round1.end(), My_order());
	// 6.2 打印比赛结果
	cout << "第2轮比赛名次：" << endl;
	for_each(winners_round1.begin(), winners_round1.end(), My_print1);
	cout << endl;
	cout << "--------------- 第2轮比赛完毕 ---------------" << endl;
	system("pause");

	// 7 第2轮晋级选手
	// 7.1 将晋级选手装入同一个数组
	vector<Player> winners_round2;
	winners_round2.reserve(3);
	for (int i = 0; i < 3; i++)
	{
		winners_round2.push_back(winners_round1[i]);
	}
	// 7.2 对晋级名单排序
	sort(winners_round2.begin(), winners_round2.end(), My_order());
	// 7.3 打印晋级选手名单
	cout << "--------------- 第2轮晋级选手信息如下：---------------" << endl;
	for_each(winners_round2.begin(), winners_round2.end(), My_print2);
	cout << endl;
	system("pause");
	system("cls");

	// 8 保存比赛结果
	// 8.1 保存到历届比赛获奖数组
	vector<pair<int, double>> winner;
	for (int i = 0; i < 3; i++)
	{
		winner.push_back(make_pair(winners_round2[i].get_num(), winners_round2[i].get_final_score()));
	}
	contest_result.push_back(winner);
	// 8.2 更新成员变量
	total_seasons++;
	// 8.3 保存到文件
	save();
	show_menu(1);
	cout << "记录已保存" << endl << "本届比赛完毕！" << endl;
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
	cout << "编号：" << p.get_num() << "\t姓名：选手" << p.get_name() << "\t成绩：" << p.get_final_score() << endl;
}

void My_print2(const Player& p)
{
	cout << "选手编号：" << p.get_num() << "\t姓名：选手" << p.get_name() << "\t得分：" << p.get_final_score() << endl;
}

//void Contest_manager::start_contest1()
//{
//	player_sum = SUM_ORIGIN;
//}
//
//void Contest_manager::start_round(int round)
//{
//	// 1 初始化比赛选手
//	vector<Player> v;
//	for (int i = 0; i < player_sum; i++)
//	{
//		v.push_back(Player(10001 + i));
//	}
//
//	// 2 指定演讲顺序
//	cout << "第 << " << round << " >> 轮比赛选手正在抽签" << endl;
//	// 2.1 打乱顺序
//	random_shuffle(v.begin(), v.end());
//	// 2.2 分组
//
//	vector<vector<Player>> group;
//	group.reserve(2);
//	vector<Player>::const_iterator it = v.begin();
//	for (int i = 0; i < 2; i++)
//	{
//		group.push_back(vector<Player>(it, it + 6));
//		it += 6;
//	}
//	// 2.3 打印演讲顺序
//	cout << "-----------------------------" << endl;
//	cout << "抽签后演讲顺序如下：" << endl;
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
		cout << "还没有比赛记录..." << endl;
	}
	else
	{
		for (int i = 0; i < total_seasons; i++)
		{
			cout << "第" << i + 1 << "届"
				<< "\t冠军编号：" << contest_result[i][0].first << " 得分：" << contest_result[i][0].second
				<< "\t亚军编号：" << contest_result[i][1].first << " 得分：" << contest_result[i][1].second
				<< "\t季军编号：" << contest_result[i][2].first << " 得分：" << contest_result[i][2].second
				<< endl;
		}
	}

	system("pause");
	system("cls");
}

void Contest_manager::delete_result()
{
	cout << "确认清空？\n1、确认\n2、返回" << endl;
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
			cout << "请输入1~2：" << endl;
		}
	}
	switch (instruction)
	{
	case 1:
	{
		ofstream ofs(FILE, ios::trunc);
		if (!ofs.is_open())
		{
			cout << "文件不存在！" << endl;
		}
		else
		{
			contest_result.clear();
			total_seasons = 0;
			cout << "清空成功！" << endl;
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