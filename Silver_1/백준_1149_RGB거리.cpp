#include <iostream>
#include <algorithm>
using namespace std;
// i��° ������ ĥ�� �� ����� �ּڰ�, DP[i][j] �� i ��° ���� j �� ����� ä������ �ǹ�
// DP[i][0] > R, DP[i][1] > G, DP[i][2] > B
int DP[1002][3];
int cost[1002][3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    for (size_t i = 0; i < N; i++)
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    DP[0][0] = cost[0][0];
    DP[0][1] = cost[0][1];
    DP[0][2] = cost[0][2];
    for (size_t i = 1; i < N; i++)
    {
        DP[i][0] = min(DP[i - 1][1], DP[i - 1][2]) + cost[i][0];
        DP[i][1] = min(DP[i - 1][0], DP[i - 1][2]) + cost[i][1];
        DP[i][2] = min(DP[i - 1][0], DP[i - 1][1]) + cost[i][2];
    }
    cout << *min_element(DP[N - 1], DP[N - 1] + 3); // ���� min �� ��� min_element �� �ذ�
}