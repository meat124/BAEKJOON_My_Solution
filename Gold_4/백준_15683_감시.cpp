#include<iostream>
#include<vector>
using namespace std;
int N , M;
struct CCTV
{
    int cctv_num; // cctv 의 번호
    int column , row; // cctv 의 좌표

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

// 사각지대의 크기를 리턴한다.
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
// direction 은 1~4 까지 존재하며 방향은 북-동-남-서 으로 회전한다.
Array Fill_1(int column , int row , int direction , Array board)
{
    if (direction == 1) // 북쪽 감시
    {
        Fill_North(column , row , board);
        return board;
    }
    else if (direction == 2) // 동쪽 감시
    {
        Fill_East(column , row , board);
        return board;
    }
    else if (direction == 3) // 남쪽 감시
    {
        Fill_South(column , row , board);
        return board;
    }
    else if (direction == 4) // 서쪽 감시
    {
        Fill_West(column , row , board);
        return board;
    }
}
Array Fill_2(int column , int row , int direction , Array board)
{
    if (direction == 1) // 남,북 감시
    {
        Fill_North(column , row , board);
        Fill_South(column , row , board);
        return board;
    }
    else if (direction == 2) // 동,서 감시
    {
        Fill_East(column , row , board);
        Fill_West(column , row , board);
        return board;
    }
}
Array Fill_3(int column , int row , int direction , Array board)
{
    if (direction == 1) // 북,동 감시
    {
        Fill_North(column , row , board);
        Fill_East(column , row , board);
        return board;
    }
    else if (direction == 2) // 동,남 감시
    {
        Fill_East(column , row , board);
        Fill_South(column , row , board);
        return board;
    }
    else if (direction == 3) // 남,서 감시
    {
        Fill_South(column , row , board);
        Fill_West(column , row , board);
        return board;
    }
    else if (direction == 4) // 서,북 감시
    {
        Fill_West(column , row , board);
        Fill_North(column , row , board);
        return board;
    }
}
Array Fill_4(int column , int row , int direction , Array board)
{
    if (direction == 1) // 북,동,남 감시
    {
        Fill_North(column , row , board);
        Fill_East(column , row , board);
        Fill_South(column , row , board);
        return board;
    }
    else if (direction == 2) // 동,남,서 감시
    {
        Fill_East(column , row , board);
        Fill_South(column , row , board);
        Fill_West(column , row , board);
        return board;
    }
    else if (direction == 3) // 남,서,북 감시
    {
        Fill_South(column , row , board);
        Fill_West(column , row , board);
        Fill_North(column , row , board);
        return board;
    }
    else if (direction == 4) // 서,북,동 감시
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
    // CCTV 가 감시 가능한 영역은 # 으로 초기화 한다.
    // 각 번호의 cctv 의 감시 경우의 수 > (4,2,4,4,1)
    // 즉 cctv 가 최대 8개 존재하고 최악의 경우 > 4^8 = 2^16(65536) 의 경우의 수가 존재한다.
    // 따라서 모든 경우의 수를 모두 검사한다.
    Array array(office);
    office_vec.push_back(array);
    Monitoring(0);
    cout << min_blind_spot;
}