#include <iostream>
using namespace std;
int N;
int sequence[1002];
int DP[1002]; // DP[i] �� sequnce[i] ������ ���� �� �κ� ���� ����

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> sequence[i];
    DP[0] = 1;
    int max = DP[0];
    for (int i = 1; i < N; i++)
    {
        DP[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (sequence[i] > sequence[j])
            {
                DP[i] = DP[i] > DP[j] + 1 ? DP[i] : DP[j] + 1;
            }
        }
        max = max > DP[i] ? max : DP[i];
    }
    cout << max;
}