#include<bits/stdc++.h>
using namespace std;
// 17182 우주 탐사선
int N , K;
int adj[12][12];
bool Visit[12];
int result = 0x7FFFFFFF;

void DFS(int cur , int dist , int Visit_num)
{
    // 만약 총 거리가 result 보다 크다면 종료
    if (dist > result)
        return;
    if (Visit_num == N)
    {
        result = min(result , dist);
        return;
    }
    for (int i = 1;i <= N;i++)
    {
        if (Visit[i])
            continue;
        Visit[i] = true;
        DFS(i , dist + adj[cur][i] , Visit_num + 1);
        Visit[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    K++;
    for (int i = 1;i <= N;i++)
        for (int j = 1;j <= N;j++)
            cin >> adj[i][j];
    for (int k = 1;k <= N;k++)
        for (int i = 1;i <= N;i++)
            for (int j = 1;j <= N;j++)
                if (adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
    Visit[K] = true;
    DFS(K , 0 , 1);
    cout << result;
}