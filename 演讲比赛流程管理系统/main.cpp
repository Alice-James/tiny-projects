#include <iostream>
using namespace std;
#include "Contest_manager.h"
#include <ctime>

#include "Player.h"
#include <algorithm>
#include <functional>


void test01()
{
    Contest_manager cm;
    int instruction = 0;
    while (1)
    {
        cm.show_menu();
        cin >> instruction;
        switch (instruction)
        {
        case 0:
        {
            cm.quit();

            break;
        }

        case 1:
        {
            cm.start_contest();

            break;
        }

        case 2:
        {
            cm.show_result();

            break;
        }

        case 3:
        {
            cm.delete_result();

            break;
        }

        default:
        {
            system("cls");

            break;
        }
        }
    }
}

//void test02()
//{
//    class My_print
//    {
//    public:
//
//        void operator()(Player p)
//        {
//            cout << "编号：" << p.get_num() << " 姓名：选手" << p.get_name() << " 成绩：" << p.get_final_score() << endl;
//        }
//    };
//
//    class My_order
//    {
//    public:
//
//        bool operator()(Player p1, Player p2)
//        {
//            if (p1.get_final_score() == p2.get_final_score())
//            {
//                return p1.get_num() < p2.get_num();
//            }
//
//            return p1.get_final_score() > p2.get_final_score();
//        }
//    };
//
//    vector<Player> v;
//    for (int i = 0; i < 12; i++)
//    {
//        v.push_back(Player(10001 + i));
//    }
//    //for_each(v.begin(), v.end(), My_print());
//    //cout << endl;
//
//    //random_shuffle(v.begin(), v.end());
//    //for_each(v.begin(), v.end(), My_print());
//    //cout << endl;
//
//    //sort(v.begin(), v.end(), My_order());
//    //for_each(v.begin(), v.end(), My_print());
//    //cout << endl;
//
//    //for_each(v.begin(), v.end(), std::mem_fn(&Player::print1));
//
//}

int main()
{
    srand((unsigned int)time(NULL));

    test01();

    return 0;
}