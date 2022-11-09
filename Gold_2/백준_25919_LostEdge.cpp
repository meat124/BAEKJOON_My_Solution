#include<bits/stdc++.h>
using namespace std;
struct user
{
    int x , y , lev , exp;
    user(int x , int y , int lev , int exp) : x(x) , y(y) , lev(lev) , exp(exp) {}
};
int N , M , L , E , K;
pair<int , int> st;
int board[105][105];
int dx[4] = { 1,0,-1,0 } , dy[4] = { 0,1,0,-1 };
bool vis[105][105];
bool to_raid;
// 시작점에서 계속해서 BFS 를 시행하면서 만약 새로운 경험치를 얻을 수 있는 구간을 발견하면 true를 리턴한다.
// true 가 리턴되면 계속해서 BFS 를 시행한다.(레벨과 경험치를 올리면서)
// 만약 false 가 리턴되었는데 아직 목표 레벨에 도달하지 못했거나 레이드 위치까지 도달하지 못한 경우
// 레이드가 불가하므로 x 를 출력한다.
// 만약 false 가 리턴되었고 목표 레벨에 도달했고, 레이드 위치도 발견한 경우
// 레이드가 가능하므로 o 를 출력한다.

int BFS() // 시작 레벨과 경험치를 인자로 받는다.
{
    for (int i = 0;i < N;i++)
        fill(vis[i] , vis[i] + M , false);
    queue<pair<int , int>> Q;
    Q.push(st);
    int add_exp = 0;
    vis[st.first][st.second] = true;

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.first + dx[i] , ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (vis[nx][ny] || board[nx][ny] == -1)
                continue;
            if (board[nx][ny] == -2)
                to_raid = true;
            if (board[nx][ny] >= L)
                continue;
            if (board[nx][ny] > 0 && board[nx][ny] < L)
            {
                add_exp += board[nx][ny];
                board[nx][ny] = 0;
            }
            Q.push({ nx,ny });
            vis[nx][ny] = true;
        }
    }
    return add_exp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    cin >> L >> E >> K;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
        {
            cin >> board[i][j];
            if (board[i][j] == -3)
                st = { i,j };
        }
    while (true)
    {
        int add_exp = BFS();
        E += add_exp;
        while (E >= L)
        {
            E -= L;
            L++;
        }
        if (to_raid && L >= K)
        {
            cout << "O";
            return 0;
        }
        else if (add_exp == 0 && to_raid && L < K)
        {
            cout << "X";
            return 0;
        }
        else if (add_exp == 0 && !to_raid)
        {
            cout << "X";
            return 0;
        }
    }
}
