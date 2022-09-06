#include<bits/stdc++.h>
using namespace std;
int n , m;
int adj[105][105];
int nxt[105][105];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        fill(adj[i] , adj[i] + n + 1 , 200000000);
    for (int i = 0;i < m;i++)
    {
        int a , b , cost;
        cin >> a >> b >> cost;
        adj[a][b] = min(adj[a][b] , cost);
        nxt[a][b] = b;
    }
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
            {
                if (i == j)
                    adj[i][j] = 0;
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= n;j++)
            if (adj[i][j] == 200000000)
                cout << "0 ";
            else
                cout << adj[i][j] << " ";
        cout << "\n";
    }
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= n;j++)
        {
            if (adj[i][j] == 0 || adj[i][j] == 200000000)
            {
                cout << 0 << "\n";
                continue;
            }
            vector<int> path;
            int start = i;
            while (start != j)
            {
                path.push_back(start);
                start = nxt[start][j];
            }
            path.push_back(j);
            cout << path.size() << " ";
            for (auto p : path)
                cout << p << " ";
            cout << "\n";
        }
}