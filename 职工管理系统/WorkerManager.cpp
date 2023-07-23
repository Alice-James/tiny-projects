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
    cout << "*********  ��ӭʹ��ְ������ϵͳ�� *********" << endl;
    cout << "*************  0.�˳�������� *************" << endl;
    cout << "*************  1.����ְ����Ϣ *************" << endl;
    cout << "*************  2.��ʾְ����Ϣ *************" << endl;
    cout << "*************  3.ɾ����ְְ�� *************" << endl;
    cout << "*************  4.�޸�ְ����Ϣ *************" << endl;
    cout << "*************  5.����ְ����Ϣ *************" << endl;
    cout << "*************  6.���ձ������ *************" << endl;
    cout << "*************  7.��������ĵ� *************" << endl;
    cout << "*******************************************" << endl;
    cout << endl << "����������ѡ��" << endl;
}

void WorkerManager::quit_worker_manager()
{
    cout << "��ӭ�ٴ�ʹ�ã�" << endl;
    exit(0);
}

void WorkerManager::add_worker()
{
    /* ��ԭ���������� */
    int add_num;
    cout << "���������ְ����������" << endl;
    while (1)
    {
        cin >> add_num;
        if (add_num <= 0)
        {
            cout << "������һ����������" << endl;
        }
        else
        {
            break;
        }
    }
    Worker** new_worker_array = new Worker * [worker_sum + add_num];// �����������ռ�
    // �Ѿ��������Ϣ���Ƶ�������
    for (int i = 0; i < worker_sum; i++)
    {
        new_worker_array[i] = worker_array[i];
    }
    delete[] worker_array;// �ͷž������ڴ�ռ�
    worker_array = new_worker_array;// ��worker_arrayָ�������飬�����������

    
    /* ������ְ������Ϣд������ */
    int ID, job;
    string name;
    int index = worker_sum;
    for (int i = 0; i < add_num; i++)
    {
        cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
        cin >> ID;
        cout << "������� " << i + 1 << " ����ְ��������" << endl;
        cin >> name;
        cout << "��ѡ���ְ���ĸ�λ��\n1����ְͨ��\n2������\n3���ܲ�" << endl;
        while (1)
        {
            cin >> job;
            if (job < 1 || job > 3)
            {
                cout << "������1~3�е�һ������" << endl;
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


    worker_sum += add_num;// ����ְ������
    save();// �����ļ�
    cout << "�ɹ����" << add_num << "����ְ����" << endl;
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
    if (!ifs.is_open())// �ļ�������
    {
        result = 1;
    }
    else
    {
        char temp;
        ifs >> temp;
        if (ifs.eof())// �ļ�Ϊ��
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
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        return;
    }

    int src_ID;
    cout << "��������Ҫɾ����ְ���ţ�" << endl;
    cin >> src_ID;
    int result = search_worker(src_ID);
    if(result == -1)
    {
        cout << "δ�ҵ����Ϊ��" << src_ID << " ��ְ����" << endl;
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
        cout << "ɾ���ɹ���" << endl;
    }
}

void WorkerManager::modify_worker_by_ID()
{
    if (worker_sum == 0)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        return;
    }

    int src_ID;
    cout << "�������޸�ְ���ı�ţ�" << endl;
    cin >> src_ID;
    int result = search_worker(src_ID);
    if (result == -1)
    {
        cout << "δ�ҵ����Ϊ��" << src_ID << " ��ְ����" << endl;
    }
    else
    {
        int new_ID, new_job;
        string new_name;
        cout << "�鵽��" << src_ID << "��ְ������������ְ���ţ�" << endl;
        cin >> new_ID;
        cout << "��������������" << endl;
        cin >> new_name;
        cout << "��ѡ���ְ���ĸ�λ��\n1����ְͨ��\n2������\n3���ܲ�" << endl;
        while (1)
        {
            cin >> new_job;
            if (new_job < 1 || new_job > 3)
            {
                cout << "������1~3�е�һ������" << endl;
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
        cout << "�޸ĳɹ���" << endl;
    }
}

void WorkerManager::search_worker()
{
    if (worker_sum == 0)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        return;
    }

    int instruction;
    cout << "��������ҵķ�ʽ��\n1����ְ����Ų���\n2������������" << endl;
    while (1)
    {
        cin >> instruction;
        if (instruction == 1 || instruction == 2)
        {
            break;
        }
        else
        {
            cout << "������1��2��" << endl;
        }
    }
    if (instruction == 1)
    {
        int src_ID;
        cout << "��������ҵ�ְ����ţ�" << endl;
        cin >> src_ID;
        int result = search_worker(src_ID);
        if (result == -1)
        {
            cout << "δ�ҵ����Ϊ��" << src_ID << " ��ְ����" << endl;
        }
        else
        {
            cout << "���ҳɹ�����ְ����Ϣ���£�" << endl
                << *(worker_array[result]) << endl;
        }
    }
    else if (instruction == 2)
    {
        string src_name;
        cout << "��������ҵ�ְ��������" << endl;
        cin >> src_name;
        int result = search_worker(src_name);
        if (result == -1)
        {
            cout << "δ�ҵ�����Ϊ��" << src_name << " ��ְ����" << endl;
        }
        else
        {
            cout << "���ҳɹ�����ְ����Ϣ���£�" << endl
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
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        return;
    }

    cout << "��ѡ������ʽ��\n1����ְ���Ž�������\n2����ְ���Ž��н���" << endl;
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
            cout << "������1��2��" << endl;
        }
    }
    sort_worker(instruction);
    cout << "����ɹ����������Ϊ��" << endl;
    show_worker_all();
}

void WorkerManager::sort_worker(int instruction)
{
    switch (instruction)
    {
    case 1:// ������������
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

    case 2:// ���ս�������
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
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
        return;
    }

    cout << "ȷ����գ�\n1��ȷ��\n2������" << endl;
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
            cout << "������1��2��" << endl;
        }
    }
    if (instruction == 1)
    {
        worker_sum = 0;
        save();
        cout << "��ճɹ���" << endl;
    }
}
