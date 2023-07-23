#include "WorkerManager.h"


WorkerManager::WorkerManager()
{
    if (file_is_empty())
    {
        this->worker_sum = 0;
        this->worker_array = NULL;
    }
    else
    {
        this->worker_sum = get_worker_sum();
        initialize_worker_array();
    }
}

WorkerManager::~WorkerManager()
{
    if (worker_array != NULL)
    {
        for (int i = 0; i < worker_sum; i++)
        {
            delete worker_array[i];
        }
        delete[] worker_array;
        worker_array = NULL;
    }
}

void WorkerManager::show_menu()
{
    cout << "*******************************************" << endl;
    cout << "*********  欢迎使用职工管理系统！ *********" << endl;
    cout << "*************  0.退出管理程序 *************" << endl;
    cout << "*************  1.增加职工信息 *************" << endl;
    cout << "*************  2.显示职工信息 *************" << endl;
    cout << "*************  3.删除离职职工 *************" << endl;
    cout << "*************  4.修改职工信息 *************" << endl;
    cout << "*************  5.查找职工信息 *************" << endl;
    cout << "*************  6.按照编号排序 *************" << endl;
    cout << "*************  7.清空所有文档 *************" << endl;
    cout << "*******************************************" << endl;
    cout << endl << "请输入您的选择：" << endl;
}

void WorkerManager::quit_worker_manager()
{
    cout << "欢迎再次使用！" << endl;
    exit(0);
}

void WorkerManager::add_worker()
{
    /* 给原有数组扩容 */
    int add_num;
    cout << "请输入添加职工的数量：" << endl;
    while (1)
    {
        cin >> add_num;
        if (add_num <= 0)
        {
            cout << "请输入一个正整数：" << endl;
        }
        else
        {
            break;
        }
    }
    Worker** new_worker_array = new Worker * [worker_sum + add_num];// 给新数组分配空间
    // 把旧数组的信息复制到新数组
    for (int i = 0; i < worker_sum; i++)
    {
        new_worker_array[i] = worker_array[i];
    }
    delete[] worker_array;// 释放旧数组内存空间
    worker_array = new_worker_array;// 让worker_array指向新数组，完成数组扩容

    
    /* 将新增职工的信息写入数组 */
    int ID, job;
    string name;
    int index = worker_sum;
    for (int i = 0; i < add_num; i++)
    {
        cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
        cin >> ID;
        cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
        cin >> name;
        cout << "请选择该职工的岗位：\n1、普通职工\n2、经理\n3、总裁" << endl;
        while (1)
        {
            cin >> job;
            if (job < 1 || job > 3)
            {
                cout << "请输入1~3中的一个数：" << endl;
            }
            else
            {
                break;
            }
        }
        Worker* new_worker = NULL;
        switch (job)
        {
        case 1:
        {
            new_worker = new Employee(ID, name, job);
            break;
        }

        case 2:
        {
            new_worker = new Manager(ID, name, job);
            break;
        }

        case 3:
        {
            new_worker = new Boss(ID, name, job);
            break;
        }

        default:
            break;
        }
        worker_array[index] = new_worker;
        index++;
    }


    worker_sum += add_num;// 更新职工总数
    save();// 更新文件
    cout << "成功添加" << add_num << "名新职工！" << endl;
}

void WorkerManager::save()
{
    ofstream ofs(WORKER_FILE, ios::out);
    for (int i = 0; i < this->worker_sum; i++)
    {
        ofs << this->worker_array[i]->ID << '\t'
            << this->worker_array[i]->name << '\t'
            << this->worker_array[i]->job << endl;
    }
    ofs.close();
}

bool WorkerManager::file_is_empty()
{
    bool result = 0;
    ifstream ifs(WORKER_FILE, ios::in);
    if (!ifs.is_open())// 文件不存在
    {
        result = 1;
    }
    else
    {
        char temp;
        ifs >> temp;
        if (ifs.eof())// 文件为空
        {
            result = 1;
        }
    }
    ifs.close();

    return result;
}

int WorkerManager::get_worker_sum()
{
    ifstream ifs(WORKER_FILE, ios::in);
    int ID, job;
    string name;
    int counter = 0;
    while (ifs >> ID && ifs >> name && ifs >> job)
    {
        counter++;
    }
    ifs.close();

    return counter;
}

void WorkerManager::initialize_worker_array()
{
    worker_array = new Worker * [worker_sum];
    ifstream ifs(WORKER_FILE, ios::in);
    int ID, job;
    string name;
    for (int i = 0; i < worker_sum; i++)
    {
        Worker* next_worker = NULL;
        ifs >> ID >> name >> job;
        switch (job)
        {
        case 1:
        {
            next_worker = new Employee(ID, name, job);
            break;
        }

        case 2:
        {
            next_worker = new Manager(ID, name, job);
            break;
        }

        case 3:
        {
            next_worker = new Boss(ID, name, job);
            break;
        }

        default:
            break;
        }
        worker_array[i] = next_worker;
    }
    ifs.close();
}

void WorkerManager::show_worker_all()
{
    if (worker_sum == 0)
    {
        cout << "文件不存在或记录为空！" << endl;
        return ;
    }

    for (int i = 0; i < worker_sum; i++)
    {
        cout << *(worker_array[i]) << endl;
    }
}

void WorkerManager::delete_worker_by_ID()
{
    if (worker_sum == 0)
    {
        cout << "文件不存在或记录为空！" << endl;
        return;
    }

    int src_ID;
    cout << "请输入想要删除的职工号：" << endl;
    cin >> src_ID;
    int result = search_worker(src_ID);
    if(result == -1)
    {
        cout << "未找到编号为：" << src_ID << " 的职工！" << endl;
    }
    else
    {
        delete worker_array[result];
        for (int i = result; i <= worker_sum - 2; i++)
        {
            worker_array[i] = worker_array[i + 1];
        }
        worker_sum--;
        save();
        cout << "删除成功！" << endl;
    }
}

void WorkerManager::modify_worker_by_ID()
{
    if (worker_sum == 0)
    {
        cout << "文件不存在或记录为空！" << endl;
        return;
    }

    int src_ID;
    cout << "请输入修改职工的编号：" << endl;
    cin >> src_ID;
    int result = search_worker(src_ID);
    if (result == -1)
    {
        cout << "未找到编号为：" << src_ID << " 的职工！" << endl;
    }
    else
    {
        int new_ID, new_job;
        string new_name;
        cout << "查到：" << src_ID << "号职工，请输入新职工号：" << endl;
        cin >> new_ID;
        cout << "请输入新姓名：" << endl;
        cin >> new_name;
        cout << "请选择该职工的岗位：\n1、普通职工\n2、经理\n3、总裁" << endl;
        while (1)
        {
            cin >> new_job;
            if (new_job < 1 || new_job > 3)
            {
                cout << "请输入1~3中的一个数：" << endl;
            }
            else
            {
                break;
            }
        }
        Worker* new_worker = NULL;
        switch (new_job)
        {
        case 1:
        {
            new_worker = new Employee(new_ID, new_name, new_job);
            break;
        }

        case 2:
        {
            new_worker = new Manager(new_ID, new_name, new_job);
            break;
        }

        case 3:
        {
            new_worker = new Boss(new_ID, new_name, new_job);
            break;
        }

        default:
            break;
        }
        delete worker_array[result];
        worker_array[result] = new_worker;

        save();
        cout << "修改成功！" << endl;
    }
}

void WorkerManager::search_worker()
{
    if (worker_sum == 0)
    {
        cout << "文件不存在或记录为空！" << endl;
        return;
    }

    int instruction;
    cout << "请输入查找的方式：\n1、按职工编号查找\n2、按姓名查找" << endl;
    while (1)
    {
        cin >> instruction;
        if (instruction == 1 || instruction == 2)
        {
            break;
        }
        else
        {
            cout << "请输入1或2：" << endl;
        }
    }
    if (instruction == 1)
    {
        int src_ID;
        cout << "请输入查找的职工编号：" << endl;
        cin >> src_ID;
        int result = search_worker(src_ID);
        if (result == -1)
        {
            cout << "未找到编号为：" << src_ID << " 的职工！" << endl;
        }
        else
        {
            cout << "查找成功！该职工信息如下：" << endl
                << *(worker_array[result]) << endl;
        }
    }
    else if (instruction == 2)
    {
        string src_name;
        cout << "请输入查找的职工姓名：" << endl;
        cin >> src_name;
        int result = search_worker(src_name);
        if (result == -1)
        {
            cout << "未找到姓名为：" << src_name << " 的职工！" << endl;
        }
        else
        {
            cout << "查找成功！该职工信息如下：" << endl
                << *(worker_array[result]) << endl;
        }
    }
}

int WorkerManager::search_worker(int src_ID)
{
    for (int i = 0; i < worker_sum; i++)
    {
        if (src_ID == worker_array[i]->ID)
        {
            return i;
        }
    }
    return -1;
}

int WorkerManager::search_worker(string src_name)
{
    for (int i = 0; i < worker_sum; i++)
    {
        if (src_name == worker_array[i]->name)
        {
            return i;
        }
    }
    return -1;
}

void WorkerManager::sort_worker()
{
    if (worker_sum == 0)
    {
        cout << "文件不存在或记录为空！" << endl;
        return;
    }

    cout << "请选择排序方式：\n1、按职工号进行升序\n2、按职工号进行降序" << endl;
    int instruction;
    while (1)
    {
        cin >> instruction;
        if (instruction == 1 || instruction == 2)
        {
            break;
        }
        else
        {
            cout << "请输入1或2：" << endl;
        }
    }
    sort_worker(instruction);
    cout << "排序成功，排序后结果为：" << endl;
    show_worker_all();
}

void WorkerManager::sort_worker(int instruction)
{
    switch (instruction)
    {
    case 1:// 按照升序排列
    {
        Worker* temp = NULL;
        for (int i = worker_sum - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (worker_array[j]->ID > worker_array[j + 1]->ID)
                {
                    temp = worker_array[j];
                    worker_array[j] = worker_array[j + 1];
                    worker_array[j + 1] = temp;
                }
            }
        }
        save();

        break;
    }

    case 2:// 按照降序排列
    {
        Worker* temp = NULL;
        for (int i = worker_sum - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (worker_array[j]->ID < worker_array[j + 1]->ID)
                {
                    temp = worker_array[j];
                    worker_array[j] = worker_array[j + 1];
                    worker_array[j + 1] = temp;
                }
            }
        }
        save();

        break;
    }
    }
}

void WorkerManager::delete_worker_all()
{
    if (worker_sum == 0)
    {
        cout << "文件不存在或记录为空！" << endl;
        return;
    }

    cout << "确认清空？\n1、确认\n2、返回" << endl;
    int instruction;
    while (1)
    {
        cin >> instruction;
        if (instruction == 1 || instruction == 2)
        {
            break;
        }
        else
        {
            cout << "请输入1或2：" << endl;
        }
    }
    if (instruction == 1)
    {
        worker_sum = 0;
        save();
        cout << "清空成功！" << endl;
    }
}
