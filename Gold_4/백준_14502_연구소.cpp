#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int N , M;
int lab[10][10];
int test_lab[10][10]; // 바이러스 퍼트릴 연구실
vector<pair<int , int>> virus; // 바이러스 위치
vector<pair<int , int>> space; // 빈 칸 위치
vector<pair<int , int>> coord; // 연구실 좌표
vector<pair<int , int>> wall_coord; // 벽 3개의 좌표
vector<int> for_combination;
queue<pair<int , int>> Q;
bool visit[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int max_safe_area = 0;

bool Return_Wall_Coord()
{
    int length = N * M;
    for (int i = length - 1;i >= 0;i--)
        if (for_combination[i] == 1)
        {
            auto p = (coord.begin() + (length - 1 - i));
            if (lab[p->first][p->second] == 0)
                wall_coord.push_back({ p->first, p->second });
        }
    // 다음 순열로 이동
    if (wall_coord.size() == 3)
        return true;
    return false;
}
// 바이러스 퍼짐
void BFS()
{
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0;i < 4;i++)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if (test_lab[nx][ny] == 1 || test_lab[nx][ny] == 2)
                continue;
            if (visit[nx][ny] == true)
                continue;
            visit[nx][ny] = true;
            test_lab[nx][ny] = 2;
            Q.push({ nx, ny });
        }
    }
}
// 안전 영역의 크기 확인
int Cal_Safe_Area()
{
    int cur_safe_area = 0;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            if (test_lab[i][j] == 0)
                cur_safe_area++;
    return cur_safe_area;
}
void Copy_Lab()
{
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            test_lab[i][j] = lab[i][j];
}
// 방문 배열 초기화
void Clear_Visit()
{
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            visit[i][j] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
        {
            cin >> lab[i][j];
            coord.push_back({ i,j });
            if (lab[i][j] == 0)
                space.push_back({ i,j });
            else if (lab[i][j] == 2)
                virus.push_back({ i,j });
        }
    // 0을 N * M - 3 의 개수 만큼 푸시한다.
    for (int i = 0;i < N * M - 3;i++)
        for_combination.push_back(0);
    // 3개의 벽을 세우기 위해 1을 3번 푸시한다.
    for (int i = 0;i < 3;i++)
        for_combination.push_back(1);
    // 000...000111
    // 벽을 3개 세움
    // 안전 영역의 최대 크기 계산
    // 벽 세우는 경우의 수 : 연구실 최대 64칸 > 64C3 = 41664
    // 각 경우마다 BFS 돌리는 연산 : 64 * 4 = 256
    do
    {
        wall_coord.clear();
        Clear_Visit();
        if (Return_Wall_Coord())
        {
            Copy_Lab();
            for (auto i : wall_coord)
                test_lab[i.first][i.second] = 1;
            for (auto i : virus)
                Q.push({ i.first, i.second });
            BFS();
            max_safe_area = max(max_safe_area , Cal_Safe_Area());
        }
    } while (next_permutation(for_combination.begin() , for_combination.end()));
    cout << max_safe_area;
}