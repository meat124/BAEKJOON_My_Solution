#include<bits/stdc++.h>
using namespace std;
int V , E , K;
vector<int> p(1005 , -1);
vector<int> Power_Plant;
tuple<int , int , int> edge[100005];

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
    cin >> V >> E >> K;
    for (int i = 0;i < K;i++)
    {
        int n;
        cin >> n;
        Power_Plant.push_back(n);
    }
    // 발전소들을 모두 유니온
    // 발전소끼리 연결되지 않게 하고, 만약 도시에 발전소가 두 개 이상 연결되면
    // 사이클이 생기므로 유니온 하면 생기지 않게 만들 수 있다.
    for (int i = 1;i < K;i++)
        Union(Power_Plant[0] , Power_Plant[i]);
    for (int i = 0;i < E;i++)
    {
        int u , v , cost;
        cin >> u >> v >> cost;
        edge[i] = { cost, u, v };
    }
    sort(edge , edge + E);
    // 발전소가 1곳 이라면 모든 도시를 연결한 간선의 총 개수는 V - 1개 필요하다.
    // 발전소가 2곳 이라면 모든 도시를 연결한 간선의 총 개수는 V - 2개 필요하다.
    // 발전소가 K곳 이라면 모든 도시를 연결한 간선의 총 개수는 V - K개 필요하다.
    int cnt = 0;
    int result = 0;
    for (int i = 0;i < E;i++)
    {
        int cost , u , v;
        tie(cost , u , v) = edge[i];
        if (!Union(u , v))
            continue;
        cnt++;
        result += cost;
        if (cnt == V - K)
            break;
    }
    cout << result;
}