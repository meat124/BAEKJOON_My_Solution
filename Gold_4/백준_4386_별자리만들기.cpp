#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> p(105 , -1);
tuple<double , int , int> adj[10005];
// 좌표가 실수로 존재하므로 그 값을 해시값으로 저장한다.
map<pair<double , double> , int> M; // key : 좌표, value : 좌표의 코드 값

double Cal_Dist(pair<double , double> a , pair<double , double> b)
{
    double dx = abs(a.first - b.first) , dy = (a.second - b.second);
    return sqrt(dx * dx + dy * dy);
}

int Find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = Find(p[x]);
}

bool Union(int u , int v)
{
    u = Find(u) , v = Find(v);
    if (u == v)
        return false;
    if (p[u] == p[v])
        p[u]--;
    if (p[u] < p[v])
        p[v] = u;
    else
        p[u] = v;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int k = 0;
    for (int i = 0;i < n;i++)
    {
        double x , y;
        cin >> x >> y;
        for (auto j : M)
            adj[k++] = { Cal_Dist(j.first, {x,y}), i, j.second };
        M[{x , y}] = i;
    }
    sort(adj , adj + k);
    int cnt = 0;
    double result = 0;
    for (int i = 0;i < k;i++)
    {
        int a , b;
        double cost;
        tie(cost , a , b) = adj[i];
        if (!Union(a , b))
            continue;
        result += cost;
        cnt++;
        if (cnt == n - 1)
            break;
    }
    cout << result;
}