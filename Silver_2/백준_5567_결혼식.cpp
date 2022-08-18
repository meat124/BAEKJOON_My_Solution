#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n , m;
vector<int> adj[505];
queue<int> Q;
bool visit[505];
int depth[505];
int result = 0;

void BFS()
{
    Q.push(1);
    visit[1] = true;
    depth[1] = 0;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (auto nxt : adj[cur])
        {
            if (visit[nxt])
                continue;
            depth[nxt] = depth[cur] + 1;
            if (depth[nxt] > 2)
                continue;
            visit[nxt] = true;
            Q.push(nxt);
            result++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cin >> m;
    while (m--)
    {
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    BFS();
    cout << result;
}