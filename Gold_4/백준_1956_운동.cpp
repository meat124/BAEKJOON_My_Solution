#include<bits/stdc++.h>
using namespace std;
int V , E;
int adj[405][405];
int result = 0x7FFFFFFF;

int Find_Min_Cycle(int start)
{
    int total_cost = 0x7FFFFFFF;
    for (int i = 1;i <= V;i++)
    {
        if (i == start)
            continue;
        if (adj[start][i] != 10000000 && adj[i][start] != 10000000)
            total_cost = min(total_cost , adj[start][i] + adj[i][start]);
    }
    return total_cost;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    for (int i = 1;i <= V;i++)
        fill(adj[i] , adj[i] + V + 1 , 10000000);
    for (int i = 0;i < E;i++)
    {
        int a , b , cost;
        cin >> a >> b >> cost;
        adj[a][b] = cost;
    }
    for (int k = 1;k <= V;k++)
        for (int i = 1;i <= V;i++)
            for (int j = 1;j <= V;j++)
            {
                if (i == j)
                {
                    adj[i][j] = 0;
                    continue;
                }
                adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
            }
    for (int i = 1;i <= V;i++)
        result = min(result , Find_Min_Cycle(i));
    if (result == 0x7FFFFFFF)
        cout << -1;
    else
        cout << result;
}