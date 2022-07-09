#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

int R, C;
queue<pair<int, int>> Q_J;
queue<pair<int, int>> Q_F;
char maze[1005][1005];
int dist_J[1005][1005]; // J 가 이동하는데 걸리는 시간
int dist_F[1005][1005]; // F 가 이동하는데 걸리는 시간
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

void BFS()
{
	// J 의 이동 경로
	while (!Q_J.empty())
	{
		pair<int, int> cur = Q_J.front();
		Q_J.pop();
		for (size_t i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (dist_J[nx][ny] || maze[nx][ny] == '#')
				continue;
			dist_J[nx][ny] = dist_J[cur.first][cur.second] + 1;
			Q_J.push({ nx,ny });
		}
	}
	// F 의 이동 경로
	while (!Q_F.empty())
	{
		pair<int, int> cur = Q_F.front();
		Q_F.pop();
		for (size_t i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (dist_F[nx][ny] || maze[nx][ny] == '#')
				continue;
			dist_F[nx][ny] = dist_F[cur.first][cur.second] + 1;
			Q_F.push({ nx,ny });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;

	for (size_t i = 0; i < R; i++)
		for (size_t j = 0; j < C; j++)
		{
			cin >> maze[i][j];
			if (maze[i][j] == 'J')
			{
				Q_J.push({ i,j });
				dist_J[i][j] = 1; // J 가 출발하는 위치를 탈출시간 1로 초기화
			}
			else if (maze[i][j] == 'F')
			{
				Q_F.push({ i,j });
				dist_F[i][j] = 1; // F 가 출발하는 시간을 1로 초기화
			}
		}

	BFS();

	vector<int> escape_time;
	for (size_t i = 0; i < C; i++)
	{
		if (dist_J[0][i] < dist_F[0][i] || (dist_J[0][i] && dist_F[0][i] == 0))
		{
			if (dist_J[0][i] != 0)
				escape_time.push_back(dist_J[0][i]);
		}
		if (dist_J[R - 1][i] < dist_F[R - 1][i] || (dist_J[R - 1][i] && dist_F[R - 1][i] == 0))
		{
			if (dist_J[R - 1][i] != 0)
				escape_time.push_back(dist_J[R - 1][i]);
		}
	}
	for (size_t i = 0; i < R; i++)
	{
		if (dist_J[i][0] < dist_F[i][0] || (dist_J[i][0] && dist_F[i][0] == 0))
		{
			if (dist_J[i][0] != 0)
				escape_time.push_back(dist_J[i][0]);
		}
		if (dist_J[i][C - 1] < dist_F[i][C - 1] || (dist_J[i][C - 1] && dist_F[i][C - 1] == 0))
		{
			if (dist_J[i][C - 1] != 0)
				escape_time.push_back(dist_J[i][C - 1]);
		}
	}

	if (escape_time.empty())
		cout << "IMPOSSIBLE"; 
	else
		cout << *min_element(escape_time.begin(), escape_time.end());
}