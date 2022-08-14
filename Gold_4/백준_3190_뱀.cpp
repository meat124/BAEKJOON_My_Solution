#include<iostream>
#include<vector>
#include<deque>
using namespace std;
// 3190 뱀
struct condition
{
    int x , y;
    int dir; // 방향은 0은 오른쪽, 1은 아래, 2는 왼쪽, 3은 위쪽 (시계방향회전)

    condition(int x , int y , int dir)
        : x(x) , y(y) , dir(dir) {}
};
deque<condition> snake; // 뱀
int N , K , L;
bool apple[102][102];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
deque<pair<int , char>> route;
int t = 0; // 게임 시간

// 뱀의 머리가 이동할 좌표를 인자로 받는다.
// 뱀의 몸에 머리가 닿으면 true, 아니면 false 를 리턴한다.
bool crash(pair<int , int> cur)
{
    for (auto i : snake)
        if (i.x == cur.first && i.y == cur.second)
            return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N; // 보드 크기
    cin >> K; // 사과 개수
    for (int i = 0;i < K;i++)
    {
        int x , y;
        cin >> x >> y;
        apple[x - 1][y - 1] = true; // 사과의 위치
    }
    cin >> L; // 뱀의 방향 변환 횟수
    for (int i = 0;i < L;i++)
    {
        int x;
        char c;
        cin >> x >> c;
        route.push_back({ x,c }); // 뱀의 방향 변환 정보
    }
    // 길이 1 이고, 오른쪽 바라보는 뱀
    snake.push_back(condition(0 , 0 , 0));
    // 게임 시간은 1회 반복마다 1초씩 증가
    while (true)
    {
        pair<int , int> tmp_dir;
        // 방향 변환 시간이 된 경우
        if (t == route.front().first)
        {
            if (route.front().second == 'L') // 바라보는 방향의 왼쪽으로 회전
            {
                // 만약 뱀이 바라보는 방향이 0(오른쪽)이면 방향을 3으로 바꾸고, 아니면 방향값을 1 내림
                snake.back().dir == 0 ? snake.back().dir = 3 : snake.back().dir -= 1;
            }
            else if (route.front().second == 'D')
            {
                // 만약 뱀이 바라보는 방향이 3(위쪽)이면 방향을 0으로 바꾸고, 아니면 방향값을 1 올림
                snake.back().dir == 3 ? snake.back().dir = 0 : snake.back().dir += 1;
            }
            route.pop_front(); // 방향 전환 정보를 pop 한다.
        }
        // 뱀이 이동할 위치 좌표를 tmp_dir 에 저장
        tmp_dir = { snake.back().x + dx[snake.back().dir], snake.back().y + dy[snake.back().dir] };
        if (tmp_dir.first < 0 || tmp_dir.first >= N || tmp_dir.second < 0 || tmp_dir.second >= N)
        {
            t++;
            break;
        }
        if (crash(tmp_dir))
        {
            t++;
            break;
        }
        snake.push_back(condition(tmp_dir.first , tmp_dir.second , snake.back().dir));
        // 만약 이동한 위치에서 사과를 먹었다면 꼬리부분을 pop 하지 않고 다시 반복한다.
        if (apple[tmp_dir.first][tmp_dir.second])
        {
            apple[tmp_dir.first][tmp_dir.second] = false;
            t++;
            continue;
        }
        // 사과를 먹지 못했다면 꼬리부분을 pop 한다.
        snake.pop_front();
        t++;
    }
    cout << t;
}