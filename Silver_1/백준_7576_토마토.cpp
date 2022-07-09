#include <iostream>
#include <queue>

using namespace std;

int N, M;
int tomato[1002][1002];   // 토마토의 정보
int min_date[1002][1002]; // 각 토마토들이 익기까지 걸리는 시간
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> Q;
int result = 0;

bool All_Tomatoes_Riped()
{
    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < M; j++)
            if (min_date[i][j] == -1)
                return false;
    return true;
}

void BFS()
{
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
            if (min_date[nx][ny] != -1 || tomato[nx][ny] == -1) // 이미 방문했거나 토마토가 들어있지 않은 칸
                continue;
            min_date[nx][ny] = min_date[cur.first][cur.second] + 1;
            Q.push({nx, ny});
            result = result > min_date[nx][ny] ? result : min_date[nx][ny];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> M >> N;
    for (size_t i = 0; i < N; i++)
        fill_n(min_date[i], M, -1);

    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < M; j++)
        {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1)
            {
                Q.push({i, j});
                min_date[i][j] = 1;
            }
            else if (tomato[i][j] == -1)
                min_date[i][j] = -2;
        }
    if (All_Tomatoes_Riped()) // 만약 모든 토마토가 익어있다면 true;
    {
        cout << 0;
        return 0;
    }

    BFS();

    if (!All_Tomatoes_Riped()) // 만약 모든 토마토가 익지 못했다면 false > ! 연산
    {
        cout << -1;
        return 0;
    }

    cout << result - 1;
}