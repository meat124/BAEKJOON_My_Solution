#include<iostream>
using namespace std;
int n;
int board[501][501];
int result[501][501]; // result[i][j] 는 board[i][j] 까지 오는 경로에서 합의 최대

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0;i < n;i++)
        for (int j = 0;j < i + 1;j++)
            cin >> board[i][j];

    result[0][0] = board[0][0];
    for (int i = 1;i < n;i++)
        result[i][0] = result[i - 1][0] + board[i][0];

    for (int i = 1;i < n;i++)
        for (int j = 0;j < i + 1;j++)
            result[i][j] = (max(result[i - 1][j - 1] , result[i - 1][j]) + board[i][j]);

    int max_result = result[n - 1][0];
    for (int i = 1;i < n;i++)
        max_result = max_result > result[n - 1][i] ? max_result : result[n - 1][i];
    cout << max_result;
}