#include<bits/stdc++.h>
using namespace std;
int N , M , T;
int adj[305][305];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> T;
    for (int i = 1;i <= N;i++)
    {
        fill(adj[i] , adj[i] + N + 1 , 2000000);
        adj[i][i] = 0;
    }
    while (M--)
    {
        int u , v , h;
        cin >> u >> v >> h;
        adj[u][v] = h;
    }
    for (int k = 1;k <= N;k++)
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= N;j++)
                if (adj[i][j] > max(adj[i][k] , adj[k][j]))
                    adj[i][j] = max(adj[i][k] , adj[k][j]);
    while (T--)
    {
        int s , e;
        cin >> s >> e;
        if (adj[s][e] == 2000000)
            cout << -1 << "\n";
        else
            cout << adj[s][e] << "\n";
    }
}