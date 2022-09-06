#include<bits/stdc++.h>
using namespace std;
int n , m;
int adj[105][105];

void Print()
{
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
        {
            if (adj[i][j] == 200000000)
                cout << 0 << " ";
            else
                cout << adj[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    // 최소 비용의 최대값이 100,000 * 100 = 1억 까지 가능하다.
    // 따라서 초기값을 2억으로 설정한다.
    for (int i = 1;i <= n;i++)
        fill(adj[i] , adj[i] + n + 1 , 200000000);
    for (int i = 0;i < m;i++)
    {
        int a , b , cost;
        cin >> a >> b >> cost;
        adj[a][b] = min(adj[a][b] , cost);
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
            for (int k = 1;k <= n;k++)
            {
                if (j == k)
                {
                    adj[j][k] = 0;
                    continue;
                }
                adj[j][k] = min(adj[j][k] , adj[j][i] + adj[i][k]);
            }
    Print();

}