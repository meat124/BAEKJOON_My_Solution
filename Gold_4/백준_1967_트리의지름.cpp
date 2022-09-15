#include<bits/stdc++.h>
using namespace std;
int n;
pair<int , int> max_node; // 가장 먼 노드 번호와 그 거리를 저장한다.
vector<pair<int , int>> adj[10005];
vector<bool> visited(10005);
int result = 0; // 특정 부모 노드에서 자식 간의 거리가 가장 긴 값을 저장한다.

// cur 은 현재 보고 있는 노드, p 는 부모 노드
void DFS(int cur , int len)
{
    if (visited[cur])
        return;
    visited[cur] = true;
    if (max_node.second < len)
    {
        max_node.first = cur;
        max_node.second = len;
    }
    for (auto nxt : adj[cur])
        DFS(nxt.second , len + nxt.first);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0;i < n - 1;i++)
    {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({ w,v });
        adj[v].push_back({ w,u });
    }
    DFS(1 , 0);
    fill(visited.begin() , visited.end() , false);
    max_node.second = 0;
    DFS(max_node.first , 0);
    cout << max_node.second;
}