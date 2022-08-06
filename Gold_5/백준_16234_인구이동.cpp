#include<iostream>
#include<queue>
using namespace std;
int N , L , R;
int population[102][102];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cur_population = 0 , cur_nations = 0;
queue<pair<int , int>> Q;
int save[10005]; // �ִ� N*N ����
int visit[102][102];
int result = 0;
void Clear_visit()
{
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            visit[i][j] = false;
}
// ���漱�� ���� �������� �α� ������ ������ ���� ���� ������ �ʱ�ȭ�Ѵ�.
void Move()
{
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            if (visit[i][j])
                population[i][j] = save[visit[i][j]];
}
// �ʺ�켱 Ž���� �����ϸ�, �� ��ü�� �� �� Ž���Ͽ� ���漱�� ���� ����鳢�� ���� ǥ���Ѵ�.
bool BFS()
{
    int n = 1;
    bool flag = false; // ���� �α� �̵��� �Ͼ�� �ʾҴٸ� false �� �����Ѵ�.
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
                        flag = true; // �α� �̵��� �߻������Ƿ� true �� �ʱ�ȭ �Ѵ�.
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
    // �α� �̵��� �Ͼ���� true, �Ͼ�� �ʾ����� false �� �����Ѵ�.
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