#include<iostream>
#include<queue>
using namespace std;
int N;
char picture[105][105];
char picture_error[105][105];
bool visit[105][105];
queue<pair<int , int>> Q;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt = 0; // 원래 구역
int cnt_error = 0; // 색맹이 보는 구역

void BFS(char color , char(*pic)[105])
{
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (visit[nx][ny] || pic[nx][ny] != color)
                continue;
            visit[nx][ny] = true;
            Q.push({ nx,ny });
        }
    }
}

void clear()
{
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            visit[i][j] = false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
        {
            cin >> picture[i][j];
            if (picture[i][j] == 'G')
                picture_error[i][j] = 'R';
            else
                picture_error[i][j] = picture[i][j];
        }
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            if (!visit[i][j])
            {
                visit[i][j] = true;
                Q.push({ i,j });
                BFS(picture[i][j] , picture);
                cnt++;
            }
    clear();
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            if (!visit[i][j])
            {
                visit[i][j] = true;
                Q.push({ i,j });
                BFS(picture_error[i][j] , picture_error);
                cnt_error++;
            }
    cout << cnt << " " << cnt_error;
}