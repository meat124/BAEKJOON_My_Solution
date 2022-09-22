#include<bits/stdc++.h>
using namespace std;
const int INF = 7e8;
int V , E;
vector<pair<int , int>> adj[805];

// start -> end 의 최소 비용을 리턴한다.
int Dijkstra(int start , int end)
{
    int dist[805];
    fill(dist , dist + V + 1 , INF);
    dist[start] = 0;
    priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;
    // first : 거리, second : 정점 을 푸시한다.
    pq.push({ dist[start], start });
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (dist[cur.second] != cur.first)
            continue;
        // 현재 우선순위 큐에서 꺼낸 정점에 대하여 이동 가능한 정점에 대해서 탐색 진행
        for (auto nxt : adj[cur.second])
        {
            // 만약 현재 정점에서 간선을 타고 이동하는 비용보다 이미 그 정점까지 최소 비용이 작다면
            if (dist[nxt.second] <= dist[cur.second] + nxt.first)
                continue;
            dist[nxt.second] = dist[cur.second] + nxt.first;
            pq.push({ dist[nxt.second], nxt.second });
        }
    }
    return dist[end];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    while (E--)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
        adj[v].push_back({ w,u });
    }
    int p1 , p2;
    cin >> p1 >> p2;
    // 1-p1-p2-N or 1-p2-p1-N 에서 최단 경로를 구한다.
    int road1 = Dijkstra(1 , p1) + Dijkstra(p1 , p2) + Dijkstra(p2 , V);
    int road2 = Dijkstra(1 , p2) + Dijkstra(p2 , p1) + Dijkstra(p1 , V);
    int result = min(road1 , road2);
    if (result >= INF)
        cout << -1;
    else
        cout << result;
}