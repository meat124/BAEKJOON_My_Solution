#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N;
int adj[105][105];
int result[105][105];
queue<int> Q;
bool visit[105];

void BFS(int start)
{
    Q.push(start);
    visit[start] = true;
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        for (int i = 0;i < N;i++)
        {
            if (!adj[cur][i])
                continue;
            if (i == start)
            {
                result[start][start] = 1;
                continue;
            }
            if (visit[i])
                continue;
            result[start][i] = 1;
            Q.push(i);
            visit[i] = true;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            cin >> adj[i][j];
    for (int i = 0;i < N;i++)
    {
        BFS(i);
        fill(visit , visit + 105 , false);
    }
    for (int i = 0;i < N;i++)
    {
        for (int j = 0;j < N;j++)
            cout << result[i][j] << " ";
        cout << "\n";
    }
}