#include<bits/stdc++.h>
using namespace std;
int N;
char board[7000][7000];

// n은 현재 줄 번호, c는 좌표
void Star(int n , pair<int , int> c)
{
    if (n == 3)
    {
        // 단위 삼각형의 첫 번째 줄
        board[c.first][c.second] = '*';
        // 단위 삼각형의 두 번째 줄
        board[c.first + 1][c.second - 1] = '*';
        board[c.first + 1][c.second + 1] = '*';
        // 단위 삼각형의 세 번째 줄
        for (int i = -2;i <= 2;i++)
            board[c.first + 2][c.second + i] = '*';
    }
    else
    {
        Star(n / 2 , c);
        Star(n / 2 , { c.first + n / 2, c.second - n / 2 });
        Star(n / 2 , { c.first + n / 2, c.second - n / 2 + n });
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    for (int i = 0;i < N;i++)
        for (int j = 0;j < 2 * N - 1;j++)
            board[i][j] = ' ';

    Star(N , { 0,N - 1 });

    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < 2 * N - 1;j++)
            cout << board[i][j];
        cout << "\n";
    }
}