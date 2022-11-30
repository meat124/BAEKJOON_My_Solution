#include<bits/stdc++.h>
using namespace std;
int N , L , result;
int board[105][105] , board_rev[105][105];
bool ramp[105][105]; // 경사로가 존재하는 칸이면 true, 아니면 false
// 행과 열에서 경사로가 겹치는 경우는 생각하지 않는다.

bool Is_Passable(int n)
{
    for (int i = 0;i < N - 1;i++)
    {
        // 칸은 board[n][i] 로 확인한다.
        // 높이가 같은 칸이면 다음 칸으로 진행
        if (board[n][i] == board[n][i + 1])
            continue;
        // 높이 차이가 1보다 크다면 경사로를 놓아도 진행이 불가하므로 false 리턴
        if (abs(board[n][i] - board[n][i + 1]) > 1)
            return false;
        // 다음칸이 현재칸보다 낮다면 다음 방향으로 L 만큼 길이동안 높이가 같은지 확인한다.
        if (board[n][i] > board[n][i + 1])
        {
            int h = board[n][i + 1];
            for (int j = i + 1;j < i + 1 + L;j++)
            {
                if (j >= N)
                    return false;
                if (board[n][j] != h) // 만약 높이가 같지 않아서 경사로를 놓을 수 없다면 false 리턴
                    return false;
                ramp[n][j] = true;
            }
            continue;
        }
        // 다음칸이 현재칸보다 높다면 현재칸 포함해서 이전 방향으로 L 길이동안 높이가 같은지 확인한다.
        if (board[n][i] < board[n][i + 1])
        {
            int h = board[n][i];
            for (int j = i;j > i - L;j--)
            {
                if (j < 0)
                    return false;
                if (board[n][j] != h)
                    return false;
                if (ramp[n][j])
                    return false;
                ramp[n][j] = true;
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
        {
            cin >> board[i][j];
            board_rev[j][i] = board[i][j];
        }
    for (int i = 0;i < N;i++)
        if (Is_Passable(i))
            result++;
    for (int i = 0;i < N;i++)
    {
        copy(board_rev[i] , board_rev[i] + N , board[i]);
        fill(ramp[i] , ramp[i] + N , false);
    }
    for (int i = 0;i < N;i++)
        if (Is_Passable(i))
            result++;
    cout << result;
}