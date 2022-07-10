#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000002];  // DP[i] 는 i 를 1로 만들기 위한 연산의 최솟값
int pre[1000002]; // 지나온 경로 추적용 테이블

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    DP[1] = 0;
    for (size_t i = 2; i <= N; i++)
    {
        DP[i] = DP[i - 1] + 1;
        pre[i] = i - 1;
        if (i % 2 == 0 && DP[i] > DP[i / 2] + 1)
        {
            DP[i] = DP[i / 2] + 1;
            pre[i] = i / 2;
        }
        if (i % 3 == 0 && DP[i] > DP[i / 3] + 1)
        {
            DP[i] = DP[i / 3] + 1;
            pre[i] = i / 3;
        }
    }
    cout << DP[N] << "\n";
    int cur = N;
    while (true)
    {
        cout << cur << " ";
        if (cur == 1)
            break;
        cur = pre[cur];
    }
}