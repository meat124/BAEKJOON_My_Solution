#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
struct coord
{
    int x , y;
    int is_break; // 벽을 부수지 않았다면 0, 부순 상태라면 1 로 초기화된다.

    coord(int x , int y , bool is_break) : x(x) , y(y) , is_break(is_break) {}
};
int N , M;
int arr[1002][1002];
int dist[1002][1002][2]; // dist[i][j][0] 은 부수지 않은 방문배열, 1은 부순 방문배열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<coord> Q;

int BFS()
{
    Q.push(coord(0 , 0 , 0));
    // 초기에는 벽을 부수지 않은 dist 의 시작점을 1로 초기화한다.
    dist[0][0][0] = 1;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();

        if (cur.x == N - 1 && cur.y == M - 1)
            return dist[N - 1][M - 1][cur.is_break];

        for (int i = 0;i < 4;i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            // 다음 단계가 벽이고, 아직 벽을 부수지 않은 상태라면
            if (arr[nx][ny] == 1 && cur.is_break == 0)
            {
                Q.push(coord(nx , ny , 1));
                // 벽을 부수지 않은 dist 에서 + 1 을 해서 벽을 부순 dist 에 초기화한다.
                dist[nx][ny][1] = dist[cur.x][cur.y][0] + 1;
            }
            // 다음 단계가 벽이 아니고, 아직 방문하지 않았다면
            else if (arr[nx][ny] == 0 && dist[nx][ny][cur.is_break] == 0)
            {
                Q.push(coord(nx , ny , cur.is_break));
                dist[nx][ny][cur.is_break] = dist[cur.x][cur.y][cur.is_break] + 1;
            }
        }
    }
    // 만약 종료점에 도달하지 못했다면 -1 을 리턴한다.
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    string str;
    for (int i = 0;i < N;i++)
    {
        cin >> str;
        for (int j = 0;j < M;j++)
            arr[i][j] = str[j] - '0';
    }
    cout << BFS();
}