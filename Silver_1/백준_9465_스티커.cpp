#include<iostream>
using namespace std;
int T , N;
int board[2][100005];
int DP[2][100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> N;
        for (int i = 0;i < 2;i++)
            for (int j = 1;j <= N;j++)
                cin >> board[i][j];
        DP[0][1] = board[0][1];
        DP[1][1] = board[1][1];

        DP[0][2] = board[1][1] + board[0][2];
        DP[1][2] = board[0][1] + board[1][2];
        for (int i = 3;i <= N;i++)
        {
            DP[0][i] = board[0][i];
            DP[1][i] = board[1][i];
            if (DP[0][i - 2] > DP[0][i - 1])
                DP[1][i] += DP[0][i - 2];
            else
                DP[1][i] += DP[0][i - 1];
            if (DP[1][i - 2] > DP[1][i - 1])
                DP[0][i] += DP[1][i - 2];
            else
                DP[0][i] += DP[1][i - 1];
        }
        cout << max(DP[0][N] , DP[1][N]) << "\n";
        for (int i = 0;i < 2;i++)
        {
            fill(DP[i] , DP[i] + N + 1 , 0);
            fill(board[i] , board[i] + N + 1 , 0);
        }
    }
}