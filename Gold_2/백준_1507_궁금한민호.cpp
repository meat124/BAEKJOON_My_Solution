#include<bits/stdc++.h>
using namespace std;
int N;
int adj[25][25];
// 도시 간에 도로가 존재하면 true
bool is_adj[25][25];
int result;

void Find_Road()
{
    for (int k = 1;k <= N;k++)
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= N;j++)
            {
                if (i == j || i == k || j == k)
                    continue;
                if (adj[i][j] > adj[i][k] + adj[k][j])
                {
                    result = -1;
                    return;
                }
                if (adj[i][j] == adj[i][k] + adj[k][j])
                    is_adj[i][j] = false;
            }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            cin >> adj[i][j];
    // 일단 간선이 모든 도시간에 존재한다고 가정
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            if (i == j)
                continue;
            else
                is_adj[i][j] = true;
    Find_Road();
    if (result == -1)
        cout << result;
    else
    {
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= N;j++)
                if (is_adj[i][j])
                    result += adj[i][j];
        cout << result / 2;
    }
}