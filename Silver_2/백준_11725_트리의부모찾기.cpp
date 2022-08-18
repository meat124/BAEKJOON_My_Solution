#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
vector<int> adj[100005];
int p[100005]; // p[i] 는 i 노드의 부모 노드 번호

void BFS()
{
    queue<int> Q;
    Q.push(1);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (auto nxt : adj[cur])
        {
            if (p[cur] == nxt)
                continue;
            Q.push(nxt);
            p[nxt] = cur;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N - 1;i++)
    {
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    BFS();
    for (int i = 2;i <= N;i++)
        cout << p[i] << "\n";
}