#include <iostream>
using namespace std;
int DP[100002]; // DP[i] 는 sequence[i] 까지의 수열에서 구할 수 있는 연속적인 수들의 합의 최대값
int sequence[100002];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> sequence[i];
    int max = DP[0] = sequence[0];
    for (int i = 1; i < n; i++)
    {
        // DP[i - 1] > 0
        if (DP[i - 1] + sequence[i] > sequence[i])
            DP[i] = DP[i - 1] + sequence[i];
        else
            DP[i] = sequence[i];
        max = max > DP[i] ? max : DP[i];
    }
    cout << max;
}