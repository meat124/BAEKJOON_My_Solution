#include<bits/stdc++.h>
using namespace std;
int N , M;
int mem[105] , cost[105];
int DP[105][10005]; // 행은 앱의 순서, 열은 앱의 비활성화 비용

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1;i <= N;i++)
        cin >> mem[i];
    int sum = 0; // 모든 앱을 비활성화하기 위한 총 비용
    for (int i = 1;i <= N;i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1;i <= N;i++) // i 번째 앱까지 탐색할 때
        for (int j = 0;j <= sum;j++) // j 비용을 소모해서 얻을 수 있는 최대 메모리
        {
            if (j - cost[i] >= 0) // 만약 i 번째 앱을 j 비용 안에서 비활성화 가능하다면
                DP[i][j] = max(DP[i][j] , DP[i - 1][j - cost[i]] + mem[i]);
            DP[i][j] = max(DP[i][j] , DP[i - 1][j]);
        }
    // N 개의 앱을 전부 사용 가능한 부분에서 처음으로 M 보다 커지는 위치를 찾아서 출력함
    for (int i = 0;i <= sum;i++)
        if (DP[N][i] >= M)
        {
            cout << i;
            break;
        }
}