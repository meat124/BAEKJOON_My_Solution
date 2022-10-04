#include<bits/stdc++.h>
using namespace std;
int board[10][10];
vector<pair<int , int>> to_fill;


// zero indexed 사용
void Print()
{
    for (int i = 0;i < 9;i++)
    {
        for (int j = 0;j < 9;j++)
            cout << board[i][j];
        cout << "\n";
    }
}

// board[x][y] 에 value 를 넣을 수 있으면 true, 아니면 false 를 리턴한다.
bool Is_Possible(int x , int y , int value)
{
    // 3*3 보드 탐색
    for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3;i++)
        for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3;j++)
            if (board[i][j] == value)
                return false;
    // 행 탐색
    for (int i = 0;i < 9;i++)
        if (board[x][i] == value)
            return false;
    // 열 탐색
    for (int i = 0;i < 9;i++)
        if (board[i][y] == value)
            return false;
    return true;
}

void Fill_Sudoku(int idx)
{
    if (idx == to_fill.size())
    {
        Print();
        exit(0);
    }
    int x = to_fill[idx].first , y = to_fill[idx].second;
    for (int i = 1;i <= 9;i++)
    {
        if (!Is_Possible(x , y , i))
            continue;
        board[x][y] = i;
        Fill_Sudoku(idx + 1);
        board[x][y] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0;i < 9;i++)
    {
        string str;
        cin >> str;
        for (int j = 0;j < 9;j++)
        {
            board[i][j] = str[j] - '0';
            // 0인 부분을 채워야 하므로 벡터에 푸시
            if (board[i][j] == 0)
                to_fill.push_back({ i,j });
        }
    }
    Fill_Sudoku(0);
}