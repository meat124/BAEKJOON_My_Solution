#include <iostream>
#include <queue>
using namespace std;
int N, M, K;
bool board[52][52];
bool visit[52][52];
queue<pair<int, int>> Q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int result = 0;

void BFS(pair<int, int> start)
{
    while (!Q.empty())
    {
        pair<int, int> cur = Q.front();
        Q.pop();
        int nx, ny;
        for (int i = 0; i < 4; i++)
        {
            nx = cur.first + dx[i];
            ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (!board[nx][ny] || visit[nx][ny])
                continue;
            Q.push({nx, ny});
            visit[nx][ny] = true;
        }
    }
}
void Reset()
{
    result = 0;
    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++)
        {
            board[i][j] = false;
            visit[i][j] = false;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> M >> N >> K;
        for (int j = 0; j < K; j++)
        {
            int a, b;
            cin >> a >> b;
            board[b][a] = true;
        }
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                if (board[j][k] && !visit[j][k])
                {
                    Q.push({j, k});
                    BFS({j, k});
                    result++;
                }
        cout << result << "\n";
        Reset();
    }
}