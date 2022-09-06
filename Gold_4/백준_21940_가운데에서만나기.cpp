#include<bits/stdc++.h>
using namespace std;
int N , M , K;
int adj[205][205];
// 살고 있는 도시
int home[205];
int min_time = 0x7FFFFFFF;
vector<int> result , total_time;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1;i <= N;i++)
        fill(adj[i] , adj[i] + N + 1 , 400000);
    for (int i = 0;i < M;i++)
    {
        int a , b , cost;
        cin >> a >> b >> cost;
        adj[a][b] = cost;
    }
    cin >> K;
    for (int i = 1;i <= K;i++)
        cin >> home[i];
    for (int k = 1;k <= N;k++)
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= N;j++)
            {
                if (i == j)
                    adj[i][j] = 0;
                adj[i][j] = min(adj[i][j] , adj[i][k] + adj[k][j]);
            }
    for (int i = 1;i <= N;i++)
    {
        int t = 0;
        for (int p = 1;p <= K;p++)
            t = max(t , adj[home[p]][i] + adj[i][home[p]]);
        total_time.push_back(t);
        min_time = min(min_time , t);
    }
    for (int i = 0;i < total_time.size();i++)
        if (total_time[i] == min_time)
            cout << i + 1 << " ";
}