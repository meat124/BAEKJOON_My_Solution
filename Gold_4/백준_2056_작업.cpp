#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> adj[10005];
int deg[10005];
int work_time[10005];
int start_time[10005];
queue<pair<int , int>> Q;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1;i <= N;i++)
    {
        int t;
        cin >> t;
        work_time[i] = t;
        int n;
        cin >> n;
        while (n--)
        {
            int c;
            cin >> c;
            adj[c].push_back(i);
            deg[i]++;
        }
    }
    for (int i = 1;i <= N;i++)
        if (deg[i] == 0)
            Q.push({ i,0 });
    int result = 0;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        result = max(result , cur.second + work_time[cur.first]);
        for (auto nxt : adj[cur.first])
        {
            deg[nxt]--;
            start_time[nxt] = max(start_time[nxt] , cur.second + work_time[cur.first]);
            if (deg[nxt] == 0)
                Q.push({ nxt, start_time[nxt] });
        }
    }
    cout << result;
}