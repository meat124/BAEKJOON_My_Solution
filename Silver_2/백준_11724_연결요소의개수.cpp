#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
vector<int> adj[1002]; // ���� ����Ʈ
bool visit[1002];
queue<int> Q;
int result = 0; // ���� ����� ����

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // ���� ����Ʈ�� �̿��� BFS
    for (int i = 1; i <= N; i++)
    {
        if (visit[i])
            continue;
        Q.push(i);
        result++;
        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for (auto nxt : adj[cur])
            {
                if (visit[nxt])
                    continue;
                Q.push(nxt);
                visit[nxt] = true;
            }
        }
    }
    cout << result;
}