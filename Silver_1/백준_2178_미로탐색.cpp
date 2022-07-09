#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> Q;
int N, M;
string board[102];
int dist[102][102]; // 거리를 표시함과 동시에 -1 은 아직 방문하지 않았음을 나타낸다.
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS() // (N - 1, M - 1) 까지의 최단 거리를 구한다.
{
    dist[0][0] = 1;
    Q.push({0, 0});
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        for (size_t i = 0; i < 4; i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) // 미로의 크기를 초과한 경우
                continue;
            if (dist[nx][ny] != -1 || board[nx][ny] != '1') // 이미 방문 했거나 갈 수 없는 길인 경우
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1; // 이동 거리를 한 칸 늘린 값으로 초기화 한다.
            Q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < M; j++)
            dist[i][j] = -1;

    for (size_t i = 0; i < N; i++)
        cin >> board[i];
    BFS();
    cout << dist[N - 1][M - 1];
}