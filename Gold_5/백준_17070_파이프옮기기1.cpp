#include<bits/stdc++.h>
using namespace std;
struct pipe
{
    pair<int , int> front , back;
    // 파이프 초기상태 생성자
    pipe() : front({ 1,2 }) , back({ 1,1 }) {}
    pipe(pair<int , int> front , pair<int , int> back) : front(front) , back(back) {}

    void operator=(pipe& p)
    {
        front = p.front;
        back = p.back;
    }
};
int N;
int board[20][20];

pipe Move_Vertical(pipe p)
{
    int dx = p.front.first - p.back.first;
    int dy = p.front.second - p.back.second;
    // 파이프가 대각선으로 있는 경우
    if (dx && dy)
    {
        p.front.first++;
        p.back.first++;
        p.back.second++;
    }
    // 파이프가 세로로 있는 경우
    else if (dx)
    {
        p.front.first++;
        p.back.first++;
    }
    return p;
}

pipe Move_Horizontal(pipe p)
{
    int dx = p.front.first - p.back.first;
    int dy = p.front.second - p.back.second;
    // 파이프가 대각선으로 있는 경우
    if (dx && dy)
    {
        p.front.second++;
        p.back.first++;
        p.back.second++;
    }
    // 파이프가 가로로 있는 경우
    else if (dy)
    {
        p.front.second++;
        p.back.second++;
    }
    return p;
}

pipe Move_Diagonal(pipe p)
{
    int dx = p.front.first - p.back.first;
    int dy = p.front.second - p.back.second;
    // 파이프가 대각선으로 있는 경우
    if (dx && dy)
    {
        p.front.first++;
        p.front.second++;
        p.back.first++;
        p.back.second++;
    }
    // 파이프가 세로로 있는 경우
    else if (dx)
    {
        p.front.first++;
        p.front.second++;
        p.back.first++;
    }
    // 파이프가 가로로 있는 경우
    else if (dy)
    {
        p.front.first++;
        p.front.second++;
        p.back.second++;
    }
    return p;
}

int Find_Direction(pipe& p)
{
    int dx = p.front.first - p.back.first;
    int dy = p.front.second - p.back.second;
    // 대각선
    if (dx && dy)
        return 3;
    // 세로
    if (dx)
        return 1;
    // 가로
    if (dy)
        return 2;
}


int BFS()
{
    queue<pipe> Q;
    pipe p;
    Q.push(p);
    int cnt = 0;
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        // 만약 파이프가 한쪽 끝에 도달했다면 true로 초기화하고 break
        if (cur.front.first == N && cur.front.second == N)
        {
            cnt++;
            continue;
        }
        if (cur.front.first > N || cur.front.second > N)
            continue;
        int state = Find_Direction(cur);
        // 파이프 이동
        if (state != 2 && board[cur.front.first + 1][cur.front.second] == 0)
        {
            auto tmp = Move_Vertical(cur);
            Q.push(tmp);
        }
        if (state != 1 && board[cur.front.first][cur.front.second + 1] == 0)
        {
            auto tmp = Move_Horizontal(cur);
            Q.push(tmp);
        }
        if (board[cur.front.first + 1][cur.front.second + 1] == 0 && board[cur.front.first + 1][cur.front.second] == 0 && board[cur.front.first][cur.front.second + 1] == 0)
        {
            auto tmp = Move_Diagonal(cur);
            Q.push(tmp);
        }
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            cin >> board[i][j];
    cout << BFS();
}