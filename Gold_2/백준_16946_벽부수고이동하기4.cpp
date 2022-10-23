#include<bits/stdc++.h>
using namespace std;
int N , M;
int board[1005][1005];
int n_board[1005][1005];
int result[1005][1005];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool vis[1005][1005];

bool OOB(int x , int y)
{
    if (x < 0 || x >= N || y < 0 || y >= M)
        return true;
    if (vis[x][y] || board[x][y])
        return true;
    return false;
}

void BFS(int x , int y , int n)
{
    queue<pair<int , int>> Q;
    Q.push({ x,y });
    vis[x][y] = true;

    vector<pair<int , int>> tmp;
    int cnt = 0;
    while (!Q.empty())
    {
        auto cur = Q.front();
        tmp.push_back(cur);
        Q.pop();
        cnt++;
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.first + dx[i] , ny = cur.second + dy[i];
            if (OOB(nx , ny))
                continue;
            vis[nx][ny] = true;
            Q.push({ nx,ny });
        }
    }
    for (auto i : tmp)
    {
        board[i.first][i.second] = -cnt;
        n_board[i.first][i.second] = n;
    }
}

void Print(int(&arr)[1005][1005])
{
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < M;j++)
            cout << arr[i][j];
        cout << "\n";
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
        for (int j = 0;j < M;j++)
            board[i][j] = str[j] - '0';
    }
    // 미리 board 를 탐색하여 영역의 넓이를 계산하여 그 값으로 초기화한다.
    // 이때 벽은 1의 값을 가지므로 양수로 초기화 하지 않고 -넓이로 초기화한다.
    int n = 1;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
        {
            if (board[i][j]) // 빈칸이 아니라면 continue
                continue;
            // 빈칸이면 BFS 시작
            BFS(i , j , n++);
        }
    // 이제 board 를 탐색하면서 벽을 만나면 실행한다.
    // 벽 기준으로 상하좌우를 모두 확인하여 그 board 의 값이 - 인 경우, 그 값을 모두 더한다.
    // 그리고 자기 자신의 위치도 포함해야 하므로 1을 추가한다.
    // 최종적으로 그 위치의 값을 더한다.
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
        {
            // 벽이 아니면 continue
            if (board[i][j] != 1)
                continue;
            int cnt = 1; // 자기 자신 포함하므로 1부터 시작
            vector<int> is_same;
            for (int k = 0;k < 4;k++)
            {
                int nx = i + dx[k] , ny = j + dy[k];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                    continue;
                if (board[nx][ny] >= 0)
                    continue;
                bool flag = false;
                for (auto s : is_same)
                    if (s == n_board[nx][ny])
                    {
                        flag = true;
                        break;
                    }
                if (flag)
                    continue;
                is_same.push_back(n_board[nx][ny]);
                cnt += -board[nx][ny];
            }
            result[i][j] = cnt % 10;
        }
    Print(result);
}