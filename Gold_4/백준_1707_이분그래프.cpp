#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int K;
vector<int> adj[20005];
queue<int> Q;
bool visit[20005];
int set_num[20005]; // 각 정점이 어디로 들어갈지 정한다.(-1 or 1)
// 그래프의 정점의 집합을 둘로 분할하여, 각 집합에 속한 정점끼리는 서로 인접하지 않도록
// 분할 가능할 경우 > 이분 그래프라고 한다.

bool BFS(int start)
{
    Q.push(start);
    visit[start] = true;
    // 어느 집합도 소속이 아니면 1번 집합으로 넣어줌
    if (!set_num[start])
        set_num[start] = 1;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (auto nxt : adj[cur])
        {
            if (set_num[nxt] == 0)
            {
                set_num[nxt] = set_num[cur] * (-1);
                visit[nxt] = true;
                Q.push(nxt);
                continue;
            }
            if (set_num[nxt] == set_num[cur])
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K;
    while (K--)
    {
        int V , E;
        cin >> V >> E;
        while (E--)
        {
            int u , v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool flag = false;
        for (int i = 1;i <= V;i++)
        {
            if (visit[i])
                continue;
            if (BFS(i))
            {
                flag = true;
                break;
            }
        }
        fill(visit , visit + V + 1 , false);
        fill(set_num , set_num + V + 1 , 0);
        if (flag)
            cout << "NO\n";
        else
            cout << "YES\n";
        for (int i = 1;i <= V;i++)
            adj[i].clear();
    }
}