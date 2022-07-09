#include <iostream>
#include <queue>
using namespace std;

queue<pair<int, int>> Q;
int N, M;
string board[102];
int dist[102][102]; // �Ÿ��� ǥ���԰� ���ÿ� -1 �� ���� �湮���� �ʾ����� ��Ÿ����.
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void BFS() // (N - 1, M - 1) ������ �ִ� �Ÿ��� ���Ѵ�.
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
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) // �̷��� ũ�⸦ �ʰ��� ���
                continue;
            if (dist[nx][ny] != -1 || board[nx][ny] != '1') // �̹� �湮 �߰ų� �� �� ���� ���� ���
                continue;
            dist[nx][ny] = dist[cur.first][cur.second] + 1; // �̵� �Ÿ��� �� ĭ �ø� ������ �ʱ�ȭ �Ѵ�.
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