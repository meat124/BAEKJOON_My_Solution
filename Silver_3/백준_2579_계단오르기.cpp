#include <iostream>
using namespace std;
int DP[302];    // DP[i] 는 i 번째 계단까지 얻을 수 있는 점수의 최대값
int point[302]; // 각 계단의 점수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (size_t i = 1; i <= N; i++)
        cin >> point[i];
    DP[1] = point[1];
    DP[2] = point[1] + point[2];
    DP[3] = max(point[1] + point[3], point[2] + point[3]);
    for (size_t i = 4; i <= N; i++)
    {
        // DP[i] = DP[i - 2] + point[i]
        // DP[i] = DP[i - 3] + point[i - 1] + point[i] 중 최대값
        DP[i] = max(DP[i - 2] + point[i], DP[i - 3] + point[i - 1] + point[i]);
    }
    cout << DP[N];
}