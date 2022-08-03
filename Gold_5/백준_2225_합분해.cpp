#include<iostream>
using namespace std;
int N , K;
// DP[i][j] �� i �� ���� j ���� ���ؼ� ����� ����� ��
// DP[1][j] �� ��� j �̴�.
// DP[2][1] > 1����, DP[2][2] > DP[2][1] ���� 0�߰��� �� 1+1 �ؼ� 2����, DP[1][1]���� 1�߰��� �� 1���� > 3����
int DP[202][202];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    // K ���� ���ؼ� N �� �Ǵ� ����� ����
    // K - 1 ���� ���ؼ� 0~N-1 ���� ����� ����� ���� �հ� ����.
    // DP[i][j] = DP[i][j - 1] + DP[i - 1][j]
    for (int j = 1;j <= K;j++)
        DP[1][j] = j;
    for (int i = 1;i <= N;i++)
        DP[i][1] = 1;

    for (int i = 2;i <= N;i++)
        for (int j = 1;j <= K;j++)
        {
            DP[i][j] = DP[i][j - 1] + DP[i - 1][j];
            DP[i][j] %= 1000000000;
        }

    cout << DP[N][K];
}