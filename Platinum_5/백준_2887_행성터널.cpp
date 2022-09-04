#include<bits/stdc++.h>
using namespace std;
int V;
vector<int> p(100005 , -1);
vector<tuple<int , int , int>> coords;
set<pair<int , int>> x_coords , y_coords , z_coords;
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

// 행성간의 거리를 모두 구한다면
// 10^5*10^5/2 = 5*10^9 = 50억 >> TLE
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V;
    for (int i = 0;i < V;i++)
    {
        int x , y , z;
        cin >> x >> y >> z;
        x_coords.insert({ x, i });
        y_coords.insert({ y, i });
        z_coords.insert({ z, i });
    }

    auto x = x_coords.begin() , y = y_coords.begin() , z = z_coords.begin();
    for (int i = 0;i < V - 1;i++)
    {
        coords.push_back({ next(x)->first - x->first, x->second, next(x)->second });
        coords.push_back({ next(y)->first - y->first, y->second, next(y)->second });
        coords.push_back({ next(z)->first - z->first, z->second, next(z)->second });
        x++ , y++ , z++;
    }
    sort(coords.begin() , coords.end());
    // 간선의 개수는 3(V - 1)
    long long result = 0;
    int cnt = 0;
    for (int i = 0;i < coords.size();i++)
    {
        int cost , u , v;
        tie(cost , u , v) = coords[i];
        if (!Union(u , v))
            continue;
        result += cost;
        cnt++;
        if (cnt == V - 1)
            break;
    }
    cout << result;
}