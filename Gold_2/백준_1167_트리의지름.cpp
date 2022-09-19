#include<bits/stdc++.h>
using namespace std;
int V;
vector<pair<int , int>> adj[100005];
bool visited[100005];

pair<int , int> DFS(int start)
{
    // 스택에 저장할 요소는 {현재 정점 번호, 거리}
    stack<pair<int , int>> S;
    visited[start] = true;
    S.push({ start, 0 });
    int result_dist = 0 , result_node = start;
    while (!S.empty())
    {
        auto cur = S.top();
        S.pop();
        if (result_dist < cur.second)
        {
            result_dist = cur.second;
            result_node = cur.first;
        }
        for (auto i : adj[cur.first])
        {
            if (visited[i.second])
                continue;
            visited[i.second] = true;
            S.push({ i.second, cur.second + i.first });
        }
    }
    return { result_node, result_dist };
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V;
    for (int i = 0;i < V;i++)
    {
        int u;
        cin >> u;
        int v = 1;
        while (true)
        {
            cin >> v;
            if (v == -1)
                break;
            int w;
            cin >> w;
            adj[u].push_back({ w,v });
            adj[v].push_back({ w,u });
        }
    }
    // 트리의 지름을 구하는 알고리즘을 작성하여라
    // 트리의 지름 : 임의의 두 점 사이의 거리 중 가장 긴 것
    // 먼저 루트에서 가장 먼 거리에 있는 정점을 찾는다.
    // 그리고 그 점에서 다시 가장 먼 거리에 있는 정점을 찾는다.
    // 그 거리가 트리의 지름이다.
    // 어느 한 정점에서 가장 먼 거리에 있는 정점을 찾는 알고리즘은 DFS 를 이용한다.
    int node1;
    node1 = DFS(1).first;
    fill(visited , visited + V + 1 , false);
    cout << DFS(node1).second;
}