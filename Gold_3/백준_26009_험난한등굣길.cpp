#include<bits/stdc++.h>
using namespace std;
struct info
{
    int x , y , dist;
    info(int x , int y , int dist) : x(x) , y(y) , dist(dist) {}
};
int N , M , K;
bool board[3005][3005];
bool vis[3005][3005];
int dx[4] = { 1,0,-1,0 } , dy[4] = { 0,1,0,-1 };

void Visualize_Traffic_Jam(int r , int c , int d)
{
    // 테두리만 채우면 내부는 이미 차단된 것과 같은 효과
    for (int i = 0;i <= d;i++)
    {
        if (r + i <= N)
        {
            if (c - (d - i) > 0)
                board[r + i][c - (d - i)] = true;
            if (c + (d - i) <= M)
                board[r + i][c + (d - i)] = true;
        }
        if (r - i > 0)
        {
            if (c - (d - i) > 0)
                board[r - i][c - (d - i)] = true;
            if (c + (d - i) <= M)
                board[r - i][c + (d - i)] = true;
        }
    }
}

bool OOB(int x , int y)
{
    if (x < 1 || x > N || y < 1 || y > M)
        return true;
    if (vis[x][y])
        return true;
    if (board[x][y])
        return true;
    return false;
}

int BFS()
{
    queue<info> Q;
    Q.push(info(1 , 1 , 0));
    vis[1][1] = true;

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        if (cur.x == N && cur.y == M)
            return cur.dist;
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.x + dx[i] , ny = cur.y + dy[i];
            if (OOB(nx , ny))
                continue;
            Q.push(info(nx , ny , cur.dist + 1));
            vis[nx][ny] = true;
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    cin >> K;
    while (K--)
    {
        int R , C , D;
        cin >> R >> C >> D;
        Visualize_Traffic_Jam(R , C , D);
    }
    int result = BFS();
    if (result == -1)
        cout << "NO";
    else
        cout << "YES\n" << result;
}