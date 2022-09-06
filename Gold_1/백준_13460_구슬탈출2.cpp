#include<bits/stdc++.h>
using namespace std;
struct marble
{
    pair<int , int> R , B;
    int cnt;
    marble() {}
    marble(pair<int , int> R , pair<int , int> B , int cnt)
        : R(R) , B(B) , cnt(cnt) {}
};
char board[12][12];
bool vis[12][12][12][12];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N , M;

marble Tilt(marble cur , int i , int& r_dist , int& b_dist)
{
    while (board[cur.R.first + dx[i]][cur.R.second + dy[i]] != '#' && board[cur.R.first][cur.R.second] != 'O')
    {
        cur.R.first += dx[i];
        cur.R.second += dy[i];
        r_dist++;
    }
    while (board[cur.B.first + dx[i]][cur.B.second + dy[i]] != '#' && board[cur.B.first][cur.B.second] != 'O')
    {
        cur.B.first += dx[i];
        cur.B.second += dy[i];
        b_dist++;
    }
    cur.cnt++;
    return cur;
}

void BFS(marble start)
{
    queue<marble> Q;
    Q.push(start);
    vis[start.R.first][start.R.second][start.B.first][start.B.second] = true;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        if (cur.cnt >= 10)
            break;
        for (int i = 0;i < 4;i++)
        {
            int r_dist = 0 , b_dist = 0;
            marble tmp = Tilt(cur , i , r_dist , b_dist);
            if (board[tmp.B.first][tmp.B.second] == 'O')
                continue;
            if (board[tmp.R.first][tmp.R.second] == 'O')
            {
                cout << tmp.cnt;
                return;
            }
            if (tmp.R == tmp.B)
                if (r_dist > b_dist)
                {
                    tmp.R.first -= dx[i];
                    tmp.R.second -= dy[i];
                }
                else
                {
                    tmp.B.first -= dx[i];
                    tmp.B.second -= dy[i];
                }
            if (vis[tmp.R.first][tmp.R.second][tmp.B.first][tmp.B.second])
                continue;
            vis[tmp.R.first][tmp.R.second][tmp.B.first][tmp.B.second] = true;
            Q.push(tmp);
        }
    }
    cout << -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    marble start;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 'R')
                start.R = { i, j };
            else if (board[i][j] == 'B')
                start.B = { i,j };
        }
    start.cnt = 0;
    BFS(start);
}