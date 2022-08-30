#include<bits/stdc++.h>
using namespace std;
int V , E;
// p 배열은 항상 -1 로 전체 초기화가 이루어져야 한다.
vector<int> p(100005 , -1);
tuple<int , int , int> edge[1000005];

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
    // u 트리의 크기가 v 트리보다 큰 경우
    if (p[u] <= p[v])
    {
        p[u] += p[v];
        p[v] = u;
    }
    // v 트리의 크기가 u 트리보다 큰 경우
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
    for (int i = 0;i < E;i++)
    {
        int a , b , cost;
        cin >> a >> b >> cost;
        edge[i] = tie(cost , a , b);
    }

    sort(edge , edge + E);

    // 비용이 적은 간선부터 찾아가므로 프림 알고리즘과 다르게 퍼져가는 방식이 아니다.
    // 따라서 비용이 적은 간선부터 이어나가서 간선이 V - 2 개가 되는 순간 종료하면 성립한다.

    // 간선의 개수
    int cnt = 0;
    // 유지비의 합 최솟값
    int result = 0;
    int max_cost = 0;
    for (int i = 0;i < E;i++)
    {
        int a , b , cost;
        tie(cost , a , b) = edge[i];
        // 두 점이 포함된 트리를 합치는 과정 시행
        // 이미 합쳐져 있다면 continue
        if (!Union(a , b))
            continue;
        cnt++;
        result += cost;
        if (cnt == V - 2)
            break;
    }
    cout << result;
}