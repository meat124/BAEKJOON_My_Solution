#include<bits/stdc++.h>
using namespace std;
int V , E;
const int INF = 1000000000;
vector<pair<int , int>> adj[1005];
int dist[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    fill(dist , dist + V + 1 , INF);
    while (E--)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
    }
    int start , end;
    cin >> start >> end;
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
    dist[start] = 0;
    pq.push({ dist[start], start });
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (dist[cur.second] != cur.first)
            continue;
        for (auto nxt : adj[cur.second])
        {
            if (dist[nxt.second] <= dist[cur.second] + nxt.first)
                continue;
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({ dist[nxt.second], nxt.second });
        }
    }
    cout << dist[end];
}