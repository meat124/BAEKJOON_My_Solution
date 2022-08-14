#include<iostream>
#include<vector>
using namespace std;
int board[10][10]; // 구역 범위 : 1-3,4-6,7-9
vector<pair<int , int>> blank_coord;

void Print()
{
    for (int i = 0;i < 9;i++)
    {
        for (int j = 0;j < 9;j++)
            cout << board[i][j] << " ";
        cout << "\n";
    }
}

void DFS(int level)
{
    if (level == blank_coord.size())
    {
        Print();
        exit(0);
    }
    auto cur_blank_coord = blank_coord[level];
    for (int i = 1;i <= 9;i++)
    {
        bool flag = false;
        // 3*3 정사각형에서 중복 검사
        for (int a = (cur_blank_coord.first / 3) * 3;a < (cur_blank_coord.first / 3) * 3 + 3;a++)
        {
            for (int b = (cur_blank_coord.second / 3) * 3;b < (cur_blank_coord.second / 3) * 3 + 3;b++)
                if (board[a][b] == i)
                {
                    flag = true;
                    break;
                }
            if (flag)
                break;
        }
        if (flag)
            continue;
        // 가로줄, 세로줄 중복 검사
        for (int a = 0;a < 9;a++)
        {
            if (board[cur_blank_coord.first][a] == i || board[a][cur_blank_coord.second] == i)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            continue;
        board[cur_blank_coord.first][cur_blank_coord.second] = i;
        DFS(level + 1);
        board[cur_blank_coord.first][cur_blank_coord.second] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0;i < 9;i++)
        for (int j = 0;j < 9;j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                blank_coord.push_back({ i,j });
        }
    DFS(0);
}