#include<bits/stdc++.h>
using namespace std;
int N , M , result;
vector<string> board;
int vis[1005][1005];

void Move(int x , int y , int cnt)
{
    vis[x][y] = cnt;
    while (true)
    {
        int nxt_x = x , nxt_y = y;
        if (board[x][y] == 'U')
            nxt_x--;
        else if (board[x][y] == 'D')
            nxt_x++;
        else if (board[x][y] == 'L')
            nxt_y--;
        else if (board[x][y] == 'R')
            nxt_y++;
        else if (board[x][y] == 'S')
            return;
        // 아직 방문하지 않은 곳이라면 방문 표시 후 continue
        if (vis[nxt_x][nxt_y] == 0)
        {
            vis[nxt_x][nxt_y] = cnt;
            x = nxt_x , y = nxt_y;
            continue;
        }
        // 이번 경로에서 방문한 곳이면 이전 위치에 safe zone 생성
        else if (vis[nxt_x][nxt_y] == cnt)
        {
            board[x][y] = 'S';
            result++;
            return;
        }
        // 이전 경로에서 방문한 곳이면 자동으로 safe zone 으로 가게 되므로 그냥 종료
        else if (vis[nxt_x][nxt_y] != cnt)
            return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < N;i++)
    {
        string str;
        cin >> str;
        board.push_back(str);
    }
    // [0][0] 에서 시작해서 [N - 1][M - 1] 까지 진행
    // 아직 방문하지 않은 위치라면 방문 표시를 남기면서 board 의 진행 방향대로 진행
    // 진행하다가 현재까지 진행한 경로를 다시 방문하면 직전 위치에 safe zone 을 생성
    // 진행하다가 다른 safe zone 으로 가는 경로를 방문하면 그대로 종료
    int cnt = 1;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
        {
            if (vis[i][j])
                continue;
            Move(i , j , cnt);
            cnt++;
        }
    }
    cout << result;
}