#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int N , M , X;
int adj[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> X;
    for (int i = 1;i <= N;i++)
    {
        fill(adj[i] , adj[i] + N + 1 , INF);
        adj[i][i] = 0;
    }
    while (M--)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }
    for (int k = 1;k <= N;k++)
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= N;j++)
                adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
    int max_time = 0;
    for (int i = 1;i <= N;i++)
        max_time = max(max_time , adj[i][X] + adj[X][i]);
    cout << max_time;
}