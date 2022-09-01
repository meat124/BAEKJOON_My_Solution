#include<bits/stdc++.h>
using namespace std;
int V , E;
vector<int> p(1005 , -1);
tuple<int , int , int> edge[500005];

int Find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = Find(p[x]);
}

bool Union(int u , int v)
{
    u = Find(u);
    v = Find(v);
    if (u == v)
        return false;
    if (p[u] <= p[v])
    {
        p[u] += p[v];
        p[v] = u;
    }
    else
    {
        p[v] += p[u];
        p[u] = v;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    for (int i = 0;i < E + 1;i++)
    {
        int a , b , cost;
        cin >> a >> b >> cost;
        edge[i] = tie(cost , a , b);
    }
    // 오름차순 정렬로 최대 스패닝 트리 구현
    sort(edge , edge + E + 1);
    int cnt = 0;
    int result_max = 0;
    for (int i = 0;i < E + 1;i++)
    {
        int a , b , cost;
        tie(cost , a , b) = edge[i];
        if (!Union(a , b))
            continue;
        cnt++;
        if (cost == 0)
            result_max++;
        if (cnt == V)
            break;
    }
    // 루트 초기화
    fill(p.begin() , p.end() , -1);
    // 내림차순 정렬로 최소 스패닝 트리 구현
    sort(edge , edge + E + 1 , greater<tuple<int , int , int>>());
    cnt = 0;
    int result_min = 0;
    for (int i = 0;i < E + 1;i++)
    {
        int a , b , cost;
        tie(cost , a , b) = edge[i];
        if (!Union(a , b))
            continue;
        cnt++;
        if (cost == 0)
            result_min++;
        if (cnt == V)
            break;
    }
    result_max *= result_max;
    result_min *= result_min;
    cout << result_max - result_min;
}