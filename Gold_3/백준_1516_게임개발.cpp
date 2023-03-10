#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> adj[505];
int deg[505];
int build_time[505];
queue<pair<int , int>> Q;
int result[505];
int start_time[505];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1;i <= N;i++)
    {
        int c;
        cin >> c;
        build_time[i] = c;
        while (c != -1)
        {
            cin >> c;
            if (c != -1)
            {
                deg[i]++;
                adj[c].push_back(i);
            }
        }
    }
    for (int i = 1;i <= N;i++)
        if (deg[i] == 0)
            Q.push({ i, 0 }); // 건물 번호와 시작 시간 푸시
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        result[cur.first] = cur.second + build_time[cur.first];
        for (int nxt : adj[cur.first])
        {
            deg[nxt]--;
            start_time[nxt] = max(start_time[nxt] , cur.second + build_time[cur.first]);
            if (deg[nxt] == 0)
                Q.push({ nxt, start_time[nxt] });
        }
    }
    for (int i = 1;i <= N;i++)
        cout << result[i] << "\n";
}