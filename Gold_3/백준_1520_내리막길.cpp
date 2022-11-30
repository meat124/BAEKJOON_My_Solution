#include<bits/stdc++.h>
using namespace std;
int N , M;
int board[505][505];
int DP[505][505]; // DP[i][j] 는 (i,j) 에서 (N - 1,M - 1) 까지 가능한 경로의 개수
int dx[4] = { 1,0,-1,0 } , dy[4] = { 0,1,0,-1 };

int DFS(int x , int y)
{
    if (x == N - 1 && y == M - 1)
        return 1;
    if (DP[x][y] != -1)
        return DP[x][y];
    DP[x][y] = 0;
    for (int i = 0;i < 4;i++)
    {
        int nx = x + dx[i] , ny = y + dy[i];
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        if (board[nx][ny] >= board[x][y])
            continue;
        DP[x][y] += DFS(nx , ny);
    }
    return DP[x][y];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
            cin >> board[i][j];
        fill(DP[i] , DP[i] + M , -1);
    }
    cout << DFS(0 , 0);
}