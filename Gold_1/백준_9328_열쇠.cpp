#include<bits/stdc++.h>
using namespace std;
int T , h , w , result;
bool keys[26] , vis[105][105];
int dx[4] = { 1,0,-1,0 } , dy[4] = { 0,1,0,-1 };
char board[105][105];

void Input()
{
    for (int i = 0;i < 105;i++)
    {
        fill(board[i] , board[i] + 105 , 0);
        fill(vis[i] , vis[i] + 105 , false);
    }
    fill(keys , keys + 26 , false);
    cin >> h >> w;
    for (int i = 1;i <= h;i++)
        for (int j = 1;j <= w;j++)
            cin >> board[i][j];
    string key;
    cin >> key;
    if (key == "0")
        return;
    for (auto i : key)
        keys[i - 'a'] = true;
}

bool OOB(int x , int y)
{
    if (x < 0 || x > h + 1 || y < 0 || y > w + 1)
        return true;
    if (vis[x][y])
        return true;
    if (board[x][y] == '*')
        return true;
    // 문인데 문을 열 수 있는 열쇠가 없는 경우
    if (board[x][y] >= 'A' && board[x][y] <= 'Z')
        if (!keys[board[x][y] - 'A'])
            return true;
    return false;
}

bool Solve()
{
    // 새로운 키를 찾으면 true 를 리턴
    for (int i = 0;i < 105;i++)
        fill(vis[i] , vis[i] + 105 , false);
    queue<pair<int , int>> Q;
    Q.push({ 0,0 });
    vis[0][0] = true;
    bool find_key = false;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        // 문서를 발견한 경우, result 를 1 증가시키고, '.' 으로 초기화한다.
        if (board[cur.first][cur.second] == '$')
        {
            result++;
            board[cur.first][cur.second] = '.';
        }
        // 키를 발견한 경우, 그 key 를 true 로 초기화하고, '.' 으로 초기화한다.
        if (board[cur.first][cur.second] >= 'a' && board[cur.first][cur.second] <= 'z')
        {
            find_key = true;
            keys[board[cur.first][cur.second] - 'a'] = true;
            board[cur.first][cur.second] = '.';
        }
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.first + dx[i] , ny = cur.second + dy[i];
            if (OOB(nx , ny))
                continue;
            Q.push({ nx,ny });
            vis[nx][ny] = true;
        }
    }
    return find_key;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        Input();
        result = 0;
        while (Solve());
        cout << result << "\n";
    }
}