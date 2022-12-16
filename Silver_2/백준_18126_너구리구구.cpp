#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll result;
vector<pair<int , int>> edge[5005];
bool vis[5005];

void DFS(int n , ll cur)
{
    if (vis[n])
        return;
    for (auto i : edge[n])
    {
        if (vis[i.first])
            continue;
        result = max(result , cur + i.second);
        vis[n] = true;
        DFS(i.first , cur + i.second);
        vis[n] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N - 1;i++)
    {
        int a , b , c;
        cin >> a >> b >> c;
        edge[a].push_back({ b,c });
        edge[b].push_back({ a,c });
    }
    DFS(1 , 0);
    cout << result;
}