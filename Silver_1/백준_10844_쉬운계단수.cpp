#include<iostream>
using namespace std;
int N;
int num_cnt[101][10];
int result = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1;i <= 9;i++)
        num_cnt[1][i] = 1;
    for (int i = 2;i <= N;i++)
    {
        for (int j = 1;j <= 8;j++)
            num_cnt[i][j] = num_cnt[i - 1][j - 1] + num_cnt[i - 1][j + 1];
        num_cnt[i][0] = num_cnt[i - 1][1];
        num_cnt[i][9] = num_cnt[i - 1][8];

        for (int j = 0;j <= 9;j++)
            num_cnt[i][j] %= 1000000000;
    }
    for (int i = 0;i <= 9;i++)
    {
        result += num_cnt[N][i];
        result %= 1000000000;
    }
    cout << result;
}