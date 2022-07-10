#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000002];  // DP[i] �� i �� 1�� ����� ���� ������ �ּڰ�
int pre[1000002]; // ������ ��� ������ ���̺�

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