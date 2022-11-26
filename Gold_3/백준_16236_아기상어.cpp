#include<bits/stdc++.h>
using namespace std;
struct fish
{
    int x , y , size;
    fish() : x(0) , y(0) , size(0) {}
    fish(int x , int y , int size) : x(x) , y(y) , size(size) {}
};
struct shark : public fish
{
    int t , cnt;
    shark() : t(0) , cnt(0) , fish(0 , 0 , 2) {}
    shark(int x , int y , int size , int t , int cnt) : t(t) , cnt(cnt) , fish(x , y , size) {}
};
int N , M , result;
int board[22][22];
int dx[4] = { -1,0,0,1 } , dy[4] = { 0,-1,1,0 };
vector<fish> F;

bool operator>(const shark& s1 , const shark& s2)
{
    if (s1.t == s2.t)
    {
        if (s1.x == s2.x)
            return s1.y > s2.y;
        return s1.x > s2.x;
    }
    return s1.t > s2.t;
}

void BFS(shark s)
{
    priority_queue<shark , vector<shark> , greater<shark>> Q;
    Q.push(s);
    bool vis[22][22];
    memset(vis , false , 22 * 22);
    vis[s.x][s.y] = true;
    while (!Q.empty())
    {
        auto cur = Q.top();
        Q.pop();
        if (board[cur.x][cur.y] && board[cur.x][cur.y] < s.size)
        {
            result += cur.t;
            cur.cnt++;
            board[cur.x][cur.y] = 0;
            if (cur.size == cur.cnt)
            {
                cur.size++;
                cur.cnt = 0;
            }
            BFS(shark(cur.x , cur.y , cur.size , 0 , cur.cnt));
            return;
        }
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.x + dx[i] , ny = cur.y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                continue;
            if (vis[nx][ny] || board[nx][ny] > cur.size)
                continue;
            vis[nx][ny] = true;
            Q.push(shark(nx , ny , cur.size , cur.t + 1 , cur.cnt));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    shark st;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                tie(st.x , st.y) = { i,j };
                board[i][j] = 0;
            }
            else if (board[i][j])
            {
                F.push_back(fish(i , j , board[i][j]));
                M++;
            }
        }
    BFS(st);
    cout << result;
}