#include<iostream>
using namespace std;
int N , K;
// DP[i][j] 는 i 를 정수 j 개를 더해서 만드는 경우의 수
// DP[1][j] 는 모두 j 이다.
// DP[2][1] > 1가지, DP[2][2] > DP[2][1] 에서 0추가한 것 1+1 해서 2가지, DP[1][1]에서 1추가한 것 1가지 > 3가지
int DP[202][202];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    // K 개를 더해서 N 이 되는 경우의 수는
    // K - 1 개를 더해서 0~N-1 까지 만드는 경우의 수의 합과 같다.
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