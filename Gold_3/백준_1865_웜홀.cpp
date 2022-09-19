#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int T , N , M , W;
vector<pair<int , int>> adj[505]; // first 는 비용, second 는 도착지
int dist[505];
// 벨만-포드 알고리즘으로 모든 노드에 대해 구해주고, 마지막에 모든 노드에 대해 다시 한 번 돌린다.
// 만약 마지막에 값이 업데이트 된다면 이는 음수 사이클이 존재하는 것이다.

bool Bellman_Ford()
{
    fill(dist , dist + N + 1 , INF); // 최단거리 배열을 INF 값으로 초기화한다.
    dist[1] = 0; // 존재해야 하는가?
    bool minus_cycle = false; // 음수 사이클 존재 유무는 초기에는 false 로 설정한다.
    for (int k = 1;k <= N;k++)
        for (int i = 1;i <= N;i++)
            for (auto nxt : adj[i])
            {
                if (dist[nxt.second] > dist[i] + nxt.first)
                {
                    dist[nxt.second] = dist[i] + nxt.first;
                    // 만약 마지막 반복인데 값이 변경된다면 음수 사이클이 존재하는 것이다.
                    if (k == N)
                        minus_cycle = true;
                }
            }
    return minus_cycle;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> N >> M >> W;
        for (int i = 1;i <= N;i++)
            adj[i].clear();
        // 도로 입력
        while (M--)
        {
            int u , v , w;
            cin >> u >> v >> w;
            // 도로는 무방향 간선이다.
            adj[u].push_back({ w,v });
            adj[v].push_back({ w,u });
        }
        // 웜홀 입력
        while (W--)
        {
            int u , v , w;
            cin >> u >> v >> w;
            // 웜홀은 유방향 간선이다.
            adj[u].push_back({ -w,v });
        }
        if (Bellman_Ford())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}