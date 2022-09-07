#include<bits/stdc++.h>
using namespace std;
int n , m , k;
int adj[300][300];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        fill(adj[i] , adj[i] + n + 1 , 1000);
        adj[i][i] = 0;
    }
    for (int i = 0;i < m;i++)
    {
        int u , v , b;
        cin >> u >> v >> b;
        if (b == 0)
        {
            adj[u][v] = 0;
            adj[v][u] = 1;
        }
        else if (b == 1)
        {
            adj[u][v] = 0;
            adj[v][u] = 0;
        }
    }

    // 플로이드 워셜
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
            {
                if (i == j)
                    continue;
                adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
            }

    cin >> k;
    for (int i = 0;i < k;i++)
    {
        int s , e;
        cin >> s >> e;
        cout << adj[s][e] << "\n";
    }
}