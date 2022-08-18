#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int N;
int board[105][105];
bool visit[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int min_h = 0x7FFFFFFF , max_h = 0; // 높이의 최소,최대값
int max_safe_area = 1;
queue<pair<int , int>> Q;

void BFS(int h) // 비가 온 높이를 인자로 받음
{
    int safe_area = 0;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
        {
            if (visit[i][j])
                continue;
            if (board[i][j] <= h)
                continue;
            // 비에 잠기지 않는 지점을 셈
            Q.push({ i,j });
            visit[i][j] = true;
            safe_area++;
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
                    if (board[nx][ny] <= h || visit[nx][ny])
                        continue;
                    visit[nx][ny] = true;
                    Q.push({ nx,ny });
                }
            }
        }
    max_safe_area = max(max_safe_area , safe_area);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
        {
            cin >> board[i][j];
            min_h = min(min_h , board[i][j]);
            max_h = max(max_h , board[i][j]);
        }
    for (int i = min_h;i < max_h;i++)
    {
        BFS(i);
        fill(&visit[0][0] , &visit[104][105] , false);
    }
    cout << max_safe_area;
}