#include<bits/stdc++.h>
using namespace std;
struct state
{
    int x , y , dist , key;
    state(int x , int y , int dist , int key) : x(x) , y(y) , dist(dist) , key(key) {}
    state(pair<int , int> c , int dist , int key) : x(c.first) , y(c.second) , dist(dist) , key(key) {}
};
int N , M;
int dx[4] = { 1,0,-1,0 } , dy[4] = { 0,1,0,-1 };
char board[55][55];
// 3번째 인덱스는 어떤 키를 가지고 있는지 비트로 표현한다.
// ex) 000101 >> a,c 키를 가지고 있음
bool vis[55][55][1 << 7];

bool OOB(int x , int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return false;
    if (board[x][y] == '#')
        return false;
    return true;
}

int BFS(pair<int , int> st)
{
    queue<state> Q;
    Q.push(state(st , 0 , 0));
    // 키를 가지지 않고 있을 때의 vis 시작 위치 true 로 초기화
    vis[st.first][st.second][0] = true;

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        if (board[cur.x][cur.y] == '1')
            return cur.dist;
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.x + dx[i] , ny = cur.y + dy[i];
            if (!OOB(nx , ny))
                continue;
            if (vis[nx][ny][cur.key])
                continue;
            if (board[nx][ny] >= 'A' && board[nx][ny] <= 'F')
                if (!(cur.key & (1 << (board[nx][ny] - 'A'))))
                    continue;
            if (board[nx][ny] >= 'a' && board[nx][ny] <= 'f')
            {
                int tmp_key = cur.key | (1 << (board[nx][ny] - 'a'));
                vis[nx][ny][tmp_key] = true;
                Q.push(state(nx , ny , cur.dist + 1 , tmp_key));
                continue;
            }
            vis[nx][ny][cur.key] = true;
            Q.push(state(nx , ny , cur.dist + 1 , cur.key));
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    pair<int , int> st;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
        {
            cin >> board[i][j];
            if (board[i][j] == '0')
            {
                st = { i,j };
                board[i][j] = '.';
            }
        }
    cout << BFS(st);
}