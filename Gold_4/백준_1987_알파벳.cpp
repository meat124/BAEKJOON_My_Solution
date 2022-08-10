#include<iostream>
using namespace std;
int R , C;
char board[22][22];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit_board[22][22];
bool visit_char[26];
int max_cnt = 1;
int cur_cnt = 1;

void DFS(pair<int , int> cur)
{
    for (int i = 0;i < 4;i++)
    {
        int nx = cur.first + dx[i];
        int ny = cur.second + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;
        if (visit_board[nx][ny] || visit_char[board[nx][ny] - 'A'])
            continue;
        visit_board[nx][ny] = true;
        visit_char[board[nx][ny] - 'A'] = true;
        cur_cnt++;
        DFS({ nx,ny });
        cur_cnt--;
        visit_board[nx][ny] = false;
        visit_char[board[nx][ny] - 'A'] = false;
    }
    max_cnt = max(max_cnt , cur_cnt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    for (int i = 0;i < R;i++)
        for (int j = 0;j < C;j++)
            cin >> board[i][j];

    visit_board[0][0] = true;
    visit_char[board[0][0] - 'A'] = true;
    DFS({ 0,0 });
    cout << max_cnt;
}