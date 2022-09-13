#include<bits/stdc++.h>
using namespace std;
int n , m , st , en;
const int INF = 1e9 + 10;
vector<pair<int , int>> adj[1005];
int dist[1005]; // 최단 거리 테이블
int prev_path[1005]; // 경로 복원 테이블

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    while (m--)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
    }
    cin >> st >> en;
    fill(dist , dist + n + 1 , INF);
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
    dist[st] = 0; // 시작점의 비용은 0으로 초기화
    pq.push({ dist[st], st }); // 비용과 시작점을 푸시
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        // 만약 현재 비용과 새로운 비용이 값이 다르다면 continue
        if (dist[cur.second] != cur.first)
            continue;
        for (auto nxt : adj[cur.second])
        {
            if (dist[nxt.second] <= dist[cur.second] + nxt.first)
                continue;
            // 최소 비용 갱신
            dist[nxt.second] = dist[cur.second] + nxt.first;
            prev_path[nxt.second] = cur.second;
            pq.push({ dist[nxt.second], nxt.second });
        }
    }
    vector<int> path;
    int cur = en;
    while (cur != st)
    {
        path.push_back(cur);
        cur = prev_path[cur];
    }
    path.push_back(cur);
    reverse(path.begin() , path.end());
    cout << dist[en] << "\n";
    cout << path.size() << "\n";
    for (auto i : path)
        cout << i << " ";
}