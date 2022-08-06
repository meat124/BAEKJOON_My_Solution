#include<iostream>
#include<queue>
using namespace std;
int N , L , R;
int population[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cur_population = 0 , cur_nations = 0;
queue<pair<int , int>> Q;
int save[10005]; // 최대 N*N 까지
int visit[102][102];
int result = 0;
void Clear_visit()
{
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            visit[i][j] = false;
}
// 국경선이 열린 국가들의 인구 총합을 국가의 수로 나눈 값으로 초기화한다.
void Move()
{
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            if (visit[i][j])
                population[i][j] = save[visit[i][j]];
}
// 너비우선 탐색을 진행하며, 땅 전체를 한 번 탐색하여 국경선이 열린 나라들끼리 전부 표시한다.
bool BFS()
{
    int n = 1;
    bool flag = false; // 만약 인구 이동이 일어나지 않았다면 false 를 리턴한다.
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
        {
            if (!visit[i][j])
            {
                visit[i][j] = n;
                cur_nations = 1;
                cur_population += population[i][j];
                Q.push({ i,j });
                while (!Q.empty())
                {
                    auto cur = Q.front();
                    Q.pop();
                    for (int k = 0;k < 4;k++)
                    {
                        int nx = cur.first + dx[k];
                        int ny = cur.second + dy[k];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                            continue;
                        if (visit[nx][ny])
                            continue;
                        if (abs(population[cur.first][cur.second] - population[nx][ny]) < L ||
                            abs(population[cur.first][cur.second] - population[nx][ny]) > R)
                            continue;
                        visit[nx][ny] = n;
                        flag = true; // 인구 이동이 발생했으므로 true 로 초기화 한다.
                        cur_population += population[nx][ny];
                        cur_nations++;
                        Q.push({ nx,ny });
                    }
                }
                save[n] = cur_population / cur_nations;
                cur_population = cur_nations = 0;
                n++;
            }
        }
    // 인구 이동이 일어났으면 true, 일어나지 않았으면 false 를 리턴한다.
    return flag;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> L >> R;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            cin >> population[i][j];
    while (BFS())
    {
        result++;
        Move();
        Clear_visit();
    }
    cout << result;
}