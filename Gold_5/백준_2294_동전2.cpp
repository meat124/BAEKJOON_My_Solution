#include<iostream>
#include<vector>
#include<set>
using namespace std;
int n , k;
int DP[100005]; // DP[i] �� i ���� ����µ� ����� ������ �ּ� ����
set<int> coin_init;
vector<int> coin_value;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0;i < n;i++)
    {
        int v;
        cin >> v;
        coin_init.insert(v);
    }
    // �ߺ� ���ŵ� ������ ��ġ�� ���Ϳ� Ǫ���Ѵ�.
    // ���� ���ʹ� �ߺ��� �������� �ʰ�, �������� ���� ����
    for (auto i : coin_init)
    {
        coin_value.push_back(i);
        DP[i] += 1;
    }
    // ���� ��ġ�� ���� �������� ����
    for (int i = coin_value[0];i <= k;i++)
    {
        // 0 �� ���, �ʱⰪ ����
        if (DP[i] == 0)
            for (auto j : coin_value)
            {
                if (i < j)
                    break;
                if (DP[i - j] == 0)
                    continue;
                DP[i] = DP[i - j] + 1;
            }
        // �ٽ� coin_value �� ���鼭 ����
        for (auto j : coin_value)
        {
            if (i < j)
                break;
            if (DP[i - j] == 0)
                continue;
            DP[i] = min(DP[i] , DP[i - j] + 1);
        }
    }
    DP[k] == 0 ? cout << "-1" : cout << DP[k];
}