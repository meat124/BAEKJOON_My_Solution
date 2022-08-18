#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N , M , V;
vector<int> adj[1005];
bool visit[1005];
queue<int> Q;

void BFS()
{
	Q.push(V);
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		visit[cur] = true;
		cout << cur << " ";
		for (auto nxt : adj[cur])
		{
			if (visit[nxt])
				continue;
			visit[nxt] = true;
			Q.push(nxt);
		}
	}
}

void DFS(int cur)
{
	if (visit[cur])
		return;
	visit[cur] = true;
	cout << cur << " ";
	for (auto nxt : adj[cur])
	{
		if (visit[nxt])
			continue;
		DFS(nxt);
	}
}

void Clear()
{
	for (int i = 0;i < 1005;i++)
		visit[i] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> V;
	while (M--)
	{
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1;i < 1005;i++)
		sort(adj[i].begin() , adj[i].end());
	DFS(V);
	cout << "\n";
	Clear();
	BFS();
}