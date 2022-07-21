#include<iostream>
#include<queue>
using namespace std;
struct coord
{
    int column , row , height;
    int day;

    coord(int z , int x , int y , int d) : column(x) , row(y) , height(z) , day(d) {}
};
int N , M , H;
int board[102][102][102];
bool visit[102][102][102];
int dx[6] = { 1,0,-1,0,0,0 };
int dy[6] = { 0,1,0,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<coord> Q;
int max_cnt = 0;

void BFS()
{
    while (!Q.empty())
    {
        coord cur = Q.front();
        Q.pop();
        for (int i = 0;i < 6;i++)
        {
            int nx = cur.column + dx[i];
            int ny = cur.row + dy[i];
            int nz = cur.height + dz[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || nz < 0 || nz >= H)
                continue;
            if (visit[nz][nx][ny] || board[nz][nx][ny] == -1 || board[nz][nx][ny] > 0)
                continue;
            visit[nz][nx][ny] = true;
            board[nz][nx][ny] = cur.day;
            Q.push(coord(nz , nx , ny , cur.day + 1));
        }
    }
}

int main()
{
    cin >> M >> N >> H;
    for (int i = 0;i < H;i++)
        for (int j = 0;j < N;j++)
            for (int k = 0;k < M;k++)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1)
                {
                    visit[i][j][k] = true;
                    Q.push(coord(i , j , k , 2));
                }
            }

    BFS();

    for (int i = 0;i < H;i++)
        for (int j = 0;j < N;j++)
            for (int k = 0;k < M;k++)
            {
                if (board[i][j][k] == 0)
                {
                    cout << -1 << "\n";
                    return 0;
                }
                max_cnt = max_cnt > board[i][j][k] ? max_cnt : board[i][j][k];
            }
    cout << max_cnt - 1 << "\n";
    return 0;
}