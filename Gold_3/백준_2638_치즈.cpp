#include<bits/stdc++.h>
using namespace std;
int N , M;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
// 외부 공기는 2, 치즈는 1, 내부 공기는 0 로 설정
int board[105][105];
bool vis[105][105];
queue<pair<int , int>> Will_Be_Melted; // 녹을 예정인 치즈 좌표를 저장한다.

void Clear_Vis()
{
    for (int i = 0;i <= N;i++)
        fill(vis[i] , vis[i] + M + 1 , false);
}

// 내부 공기를 외부 공기로 만드는 함수
void Make_Outer()
{
    Clear_Vis();
    queue<pair<int , int>> Q;
    Q.push({ 0,0 });
    board[0][0] = 2;
    vis[0][0] = true;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx > N || ny < 0 || ny > M)
                continue;
            if (board[nx][ny] == 1 || vis[nx][ny])
                continue;
            board[nx][ny] = 2;
            vis[nx][ny] = true;
            Q.push({ nx,ny });
        }
    }
}

// 격자를 탐색하면서 외부 공기에 두 면 이상 노출된 치즈를 녹인다.
void Melt()
{
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++)
        {
            if (board[i][j] != 1)
                continue;
            int cnt = 0; // 외부 공기에 노출된 면의 수
            for (int k = 0;k < 4;k++)
            {
                int nx = i + dx[k];
                int ny = j + dy[k];
                if (nx < 0 || nx > N + 1 || ny < 0 || ny > M + 1)
                    continue;
                if (board[nx][ny] == 2)
                    cnt++;
            }
            // 만약 두 면 이상 노출됐다면 녹을 예정이라고 저장
            if (cnt >= 2)
                Will_Be_Melted.push({ i,j });
        }
    // 녹을 예정인 치즈를 녹이고 외부 공기로 초기화
    while (!Will_Be_Melted.empty())
    {
        auto cur = Will_Be_Melted.front();
        Will_Be_Melted.pop();
        board[cur.first][cur.second] = 2;
    }
}

bool All_Melted()
{
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++)
            if (board[i][j] == 1)
                return false; // 아직 치즈가 다 녹지 않았다면 false
    return true; // 치즈가 모두 녹았다면 true
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= M;j++)
            cin >> board[i][j];
    Make_Outer(); // 외부 공기로 초기화
    int result = 0;
    while (!All_Melted())
    {
        Melt();
        Make_Outer();
        result++;
    }
    cout << result;
}