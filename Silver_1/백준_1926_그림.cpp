#include<iostream>
#include<queue>
using namespace std;
int board[501][501];
bool visit[501][501];
int N, M;
int drawing_cnt = 0; // �׸��� ����
int max_area = 0; // ���� ���� �׸��� ����
queue<pair<int, int>> Q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS()
{
	int cur_area = 1; // ���� ����
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (size_t i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (visit[nx][ny] || board[nx][ny] != 1)
				continue;
			visit[nx][ny] = true;
			Q.push({ nx, ny });
			cur_area++;
		}
	}
	max_area = max_area > cur_area ? max_area : cur_area; // ���� ���̿� �ִ� ���̸� ���Ͽ� �ʱ�ȭ
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++)
			cin >> board[i][j];

	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++)
		{
			if (visit[i][j] == false && board[i][j] == 1)
			{
				visit[i][j] = true; // �湮 ǥ��
				Q.push({ i,j });
				drawing_cnt++;
				BFS();
			}
		}
	cout << drawing_cnt << "\n" << max_area;
}