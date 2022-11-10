#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int N , M , X , result;
int to_X[1005] , to_home[1005];
vector<pair<int , int>> adj[1005] , adj_rev[1005]; // 기존 간선과 방향을 뒤집은 간선
priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>> pq;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> X;
    for (int i = 0;i < M;i++)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
        adj_rev[v].push_back({ w,u });
    }
    fill(to_X , to_X + N + 1 , INF);
    fill(to_home , to_home + N + 1 , INF);
    to_X[X] = to_home[X] = 0;
    pq.push({ to_X[X], X });
    // X 마을로 가는 비용을 뒤집은 간선을 이용해서 X 에서 다른 마을로 가는 것으로 계산하여 효율적으로 구한다.
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (to_X[cur.second] != cur.first)
            continue;
        for (auto nxt : adj_rev[cur.second])
        {
            if (to_X[nxt.second] <= to_X[cur.second] + nxt.first)
                continue;
            to_X[nxt.second] = to_X[cur.second] + nxt.first;
            pq.push({ to_X[nxt.second], nxt.second });
        }
    }
    pq.push({ to_home[X], X });
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        if (to_home[cur.second] != cur.first)
            continue;
        for (auto nxt : adj[cur.second])
        {
            if (to_home[nxt.second] <= to_home[cur.second] + nxt.first)
                continue;
            to_home[nxt.second] = to_home[cur.second] + nxt.first;
            pq.push({ to_home[nxt.second], nxt.second });
        }
    }
    for (int i = 1;i <= N;i++)
        result = max(result , to_X[i] + to_home[i]);
    cout << result;
}