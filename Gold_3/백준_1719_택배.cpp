#include<bits/stdc++.h>
using namespace std;
int n , m;
int adj[205][205];
int next_vertex[205][205];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        fill(adj[i] , adj[i] + n + 1 , 400000);
        adj[i][i] = 0;
    }
    while (m--)
    {
        int a , b , cost;
        cin >> a >> b >> cost;
        adj[a][b] = cost;
        adj[b][a] = cost;
        next_vertex[a][b] = b;
        next_vertex[b][a] = a;
    }
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
            {
                if (i == j || i == k || j == k)
                    continue;
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    // k 로 초기화하면 실시간으로 빠른 경로가 반영이 되지 않는다.
                    next_vertex[i][j] = next_vertex[i][k];
                }
            }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            if (next_vertex[i][j] == 0)
                cout << "- ";
            else
                cout << next_vertex[i][j] << " ";
        cout << "\n";
    }
}