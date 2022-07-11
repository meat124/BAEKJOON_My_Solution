#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, V;
bool board[1002][1002];
bool visit[1002];
queue<int> Q;

void DFS(int k) // 탐색을 시작할 번호
{
	if (visit[k] == false)
	{
		cout << k << " ";
		visit[k] = true;
	}
	for (int i = 1; i <= N; i++)
	{
		if ((board[k][i] || board[i][k]) && visit[i] == false)
		{
			visit[i] = true;
			cout << i << " ";
			DFS(i);
		}
	}
}
void BFS(int k)
{
	Q.push(k);
	if (visit[k] == false)
	{
		cout << k << " ";
		visit[k] = true;
	}
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		for (int i = 1; i <= N; i++)
		{
			if ((board[cur][i] || board[i][cur]) && visit[i] == false)
			{
				Q.push(i);
				visit[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = true;
		board[b][a] = true;
	}
	DFS(V);
	cout << "\n";
	for (int i = 1; i <= N; i++)
		visit[i] = false;
	BFS(V);

	return 0;
}