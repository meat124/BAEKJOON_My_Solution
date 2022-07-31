#include<iostream>
#include<vector>
using namespace std;
int N , M;
struct CCTV
{
    int cctv_num; // cctv �� ��ȣ
    int column , row; // cctv �� ��ǥ

    CCTV(int cctv_num , int column , int row) : cctv_num(cctv_num) , column(column) , row(row) {}
};
struct Array
{
    int arr[10][10];

    Array(int a[][10])
    {
        for (int i = 0;i < N;i++)
            for (int j = 0;j < M;j++)
                arr[i][j] = a[i][j];
    }
};
int office[10][10];
vector<CCTV> CCTV_info;
vector<Array> office_vec;
int min_blind_spot = 100;

// �簢������ ũ�⸦ �����Ѵ�.
int Count_blind_spot()
{
    int cnt = 0;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            if (office_vec.back().arr[i][j] == 0)
                cnt++;
    return cnt;
}
void Fill_North(int column , int row , Array& board)
{
    if (column == 0)
        return;
    for (int i = column - 1;i >= 0;i--)
    {
        if (board.arr[i][row] == 6)
            return;
        if (board.arr[i][row] == 0)
            board.arr[i][row] = '#';
    }
    return;
}
void Fill_East(int column , int row , Array& board)
{
    if (row == M - 1)
        return;
    for (int i = row + 1;i <= M - 1;i++)
    {
        if (board.arr[column][i] == 6)
            return;
        if (board.arr[column][i] == 0)
            board.arr[column][i] = '#';
    }
    return;
}
void Fill_South(int column , int row , Array& board)
{
    if (column == N - 1)
        return;
    for (int i = column + 1;i <= N - 1;i++)
    {
        if (board.arr[i][row] == 6)
            return;
        if (board.arr[i][row] == 0)
            board.arr[i][row] = '#';
    }
    return;
}
void Fill_West(int column , int row , Array& board)
{
    if (row == 0)
        return;
    for (int i = row - 1;i >= 0;i--)
    {
        if (board.arr[column][i] == 6)
            return;
        if (board.arr[column][i] == 0)
            board.arr[column][i] = '#';
    }
    return;
}
// direction �� 1~4 ���� �����ϸ� ������ ��-��-��-�� ���� ȸ���Ѵ�.
Array Fill_1(int column , int row , int direction , Array board)
{
    if (direction == 1) // ���� ����
    {
        Fill_North(column , row , board);
        return board;
    }
    else if (direction == 2) // ���� ����
    {
        Fill_East(column , row , board);
        return board;
    }
    else if (direction == 3) // ���� ����
    {
        Fill_South(column , row , board);
        return board;
    }
    else if (direction == 4) // ���� ����
    {
        Fill_West(column , row , board);
        return board;
    }
}
Array Fill_2(int column , int row , int direction , Array board)
{
    if (direction == 1) // ��,�� ����
    {
        Fill_North(column , row , board);
        Fill_South(column , row , board);
        return board;
    }
    else if (direction == 2) // ��,�� ����
    {
        Fill_East(column , row , board);
        Fill_West(column , row , board);
        return board;
    }
}
Array Fill_3(int column , int row , int direction , Array board)
{
    if (direction == 1) // ��,�� ����
    {
        Fill_North(column , row , board);
        Fill_East(column , row , board);
        return board;
    }
    else if (direction == 2) // ��,�� ����
    {
        Fill_East(column , row , board);
        Fill_South(column , row , board);
        return board;
    }
    else if (direction == 3) // ��,�� ����
    {
        Fill_South(column , row , board);
        Fill_West(column , row , board);
        return board;
    }
    else if (direction == 4) // ��,�� ����
    {
        Fill_West(column , row , board);
        Fill_North(column , row , board);
        return board;
    }
}
Array Fill_4(int column , int row , int direction , Array board)
{
    if (direction == 1) // ��,��,�� ����
    {
        Fill_North(column , row , board);
        Fill_East(column , row , board);
        Fill_South(column , row , board);
        return board;
    }
    else if (direction == 2) // ��,��,�� ����
    {
        Fill_East(column , row , board);
        Fill_South(column , row , board);
        Fill_West(column , row , board);
        return board;
    }
    else if (direction == 3) // ��,��,�� ����
    {
        Fill_South(column , row , board);
        Fill_West(column , row , board);
        Fill_North(column , row , board);
        return board;
    }
    else if (direction == 4) // ��,��,�� ����
    {
        Fill_West(column , row , board);
        Fill_North(column , row , board);
        Fill_East(column , row , board);
        return board;
    }
}
Array Fill_5(int column , int row , Array board)
{
    Fill_North(column , row , board);
    Fill_East(column , row , board);
    Fill_South(column , row , board);
    Fill_West(column , row , board);
    return board;
}

void Monitoring(int level)
{
    if (level == CCTV_info.size())
    {
        int cur_blind_spot = Count_blind_spot();
        min_blind_spot = min_blind_spot < cur_blind_spot ? min_blind_spot : cur_blind_spot;
        return;
    }
    if (CCTV_info[level].cctv_num == 1)
    {
        for (int i = 1;i <= 4;i++)
        {
            Array new_board = Fill_1(CCTV_info[level].column , CCTV_info[level].row , i , office_vec[level]);
            office_vec.push_back(new_board);
            Monitoring(level + 1);
            office_vec.pop_back();
        }
    }
    else if (CCTV_info[level].cctv_num == 2)
    {
        for (int i = 1;i <= 2;i++)
        {
            Array new_board = Fill_2(CCTV_info[level].column , CCTV_info[level].row , i , office_vec[level]);
            office_vec.push_back(new_board);
            Monitoring(level + 1);
            office_vec.pop_back();
        }
    }
    else if (CCTV_info[level].cctv_num == 3)
    {
        for (int i = 1;i <= 4;i++)
        {
            Array new_board = Fill_3(CCTV_info[level].column , CCTV_info[level].row , i , office_vec[level]);
            office_vec.push_back(new_board);
            Monitoring(level + 1);
            office_vec.pop_back();
        }
    }
    else if (CCTV_info[level].cctv_num == 4)
    {
        for (int i = 1;i <= 4;i++)
        {
            Array new_board = Fill_4(CCTV_info[level].column , CCTV_info[level].row , i , office_vec[level]);
            office_vec.push_back(new_board);
            Monitoring(level + 1);
            office_vec.pop_back();
        }
    }
    else if (CCTV_info[level].cctv_num == 5)
    {
        Array new_board = Fill_5(CCTV_info[level].column , CCTV_info[level].row , office_vec[level]);
        office_vec.push_back(new_board);
        Monitoring(level + 1);
        office_vec.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
        {
            cin >> office[i][j];
            if (office[i][j] >= 1 && office[i][j] <= 5)
            {
                CCTV tmp(office[i][j] , i , j);
                CCTV_info.push_back(tmp);
            }
        }
    // CCTV �� ���� ������ ������ # ���� �ʱ�ȭ �Ѵ�.
    // �� ��ȣ�� cctv �� ���� ����� �� > (4,2,4,4,1)
    // �� cctv �� �ִ� 8�� �����ϰ� �־��� ��� > 4^8 = 2^16(65536) �� ����� ���� �����Ѵ�.
    // ���� ��� ����� ���� ��� �˻��Ѵ�.
    Array array(office);
    office_vec.push_back(array);
    Monitoring(0);
    cout << min_blind_spot;
}