#include<bits/stdc++.h>
using namespace std;
int N , M;
vector<pair<int , int>> V; // 플레이어 선택
vector<int> p(500005 , -1);

// 부모 노드를 찾는 Find
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
    if (p[u] < p[v])
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
    cin >> N >> M;
    for (int i = 0;i < M;i++)
    {
        int a , b;
        cin >> a >> b;
        V.push_back({ a,b });
    }
    int cnt = 0;
    bool flag = false;
    for (auto i : V)
    {
        cnt++;
        if (Union(i.first , i.second))
            continue;
        flag = true;
        break;
    }
    if (!flag)
        cnt = 0;
    cout << cnt;
}