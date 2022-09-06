#include<bits/stdc++.h>
using namespace std;
int n , m , r;
int item[105];
int adj[105][105];
int result = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> r;
    for (int i = 1;i <= n;i++)
        cin >> item[i];
    for (int i = 1;i <= n;i++)
        fill(adj[i] , adj[i] + n + 1 , 1000000);
    for (int i = 0;i < r;i++)
    {
        int a , b , cost;
        cin >> a >> b >> cost;
        adj[a][b] = cost;
        adj[b][a] = cost;
    }
    // 플로이드-워셜 알고리즘으로 최단거리 배열을 만든 후
    // 모든 정점에서 시작해간다.
    // 시작한 정점에서 수색 범위 안에 드는 위치의 아이템의 갯수를 센다.
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
            {
                if (i == j)
                    adj[i][j] = 0;
                adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
            }
    for (int i = 1;i <= n;i++)
    {
        int cnt = 0;
        for (int j = 1;j <= n;j++)
            if (adj[i][j] <= m)
                cnt += item[j];
        result = max(result , cnt);
    }
    cout << result;
}