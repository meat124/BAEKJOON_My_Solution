#include<bits/stdc++.h>
using namespace std;
int V , E , K; // 정점, 간선, 시작점
const int INF = 1000000;
vector<pair<int , int>> adj[20005];
priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
int dist[20005]; // 최단 거리 테이블
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    cin >> K;
    // 최단거리가 존재하지 않으면 
    fill(dist , dist + V + 1 , INF);
    while (E--)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v }); // u 에서 v 로 가는 간선의 비용은 w 이다.
    }
    dist[K] = 0;
    pq.push({ dist[K],K }); // 현재 비용과 시작점을 푸시
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        // 만약 현재 보고 있는 점의 최단 거리 테이블의 값과
        // 현재 비용이 다르다면 continue
        if (dist[cur.second] != cur.first)
            continue;
        for (auto nxt : adj[cur.second])
        {
            // 만약 기존에 비용이 더 작거나 같다면 변경할 필요 없음
            if (dist[nxt.second] <= dist[cur.second] + nxt.first)
                continue;
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({ dist[nxt.second] , nxt.second });
        }
    }
    for (int i = 1;i <= V;i++)
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
}