#include<iostream>
#include<queue>
using namespace std;
int w , h;
int board[51][51];
bool visit[51][51];
queue<pair<int , int>> Q;
// 6시 부터 시작
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

void BFS()
{
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0;i < 8;i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w)
                continue;
            if (visit[nx][ny] || board[nx][ny] == 0)
                continue;
            visit[nx][ny] = true;
            Q.push({ nx,ny });
        }
    }
}

void Clear()
{
    for (int i = 0;i < h;i++)
        for (int j = 0;j < w;j++)
            visit[i][j] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        for (int i = 0;i < h;i++)
            for (int j = 0;j < w;j++)
                cin >> board[i][j];
        int cnt = 0;
        for (int i = 0;i < h;i++)
            for (int j = 0;j < w;j++)
            {
                if (board[i][j] == 1 && !visit[i][j])
                {
                    visit[i][j] = true;
                    Q.push({ i,j });
                    BFS();
                    cnt++;
                }
            }
        cout << cnt << "\n";
        Clear();
    }
}