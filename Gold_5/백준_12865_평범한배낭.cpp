#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N , K; // 물건 개수, 최대 중량
int DP[101][100001]; // DP[i][j] 는 i번째 물건까지 가방의 무게가 j 일때, 물건의 가치합을 나타낸다.
int W[101]; // 무게
int V[101]; // 가치
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;

    for (int i = 1;i <= N;i++)
        cin >> W[i] >> V[i];

    for (int i = 1;i <= N;i++) // i 번째 물건까지 생각
        for (int j = 1;j <= K;j++) // 가방의 최대 무게 j >> j 가 K 까지 갔을 때 가장 가치가 크다.
        {
            if (j >= W[i]) // 만약 가방의 최대 무게가 i 번째 물건의 무게보다 크거나 같다면 가치비교
                DP[i][j] = max(DP[i - 1][j] , DP[i - 1][j - W[i]] + V[i]);
            else // 만약 가방의 최대 무게보다 i 번째 물건의 무게가 더 크다면 이전의 값 다시 대입
                DP[i][j] = DP[i - 1][j];
        }
    cout << DP[N][K];
}