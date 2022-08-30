#include<bits/stdc++.h>
using namespace std;
int V , E;
// 부모 노드를 저장하는 배열 p
vector<int> p(1005 , -1);
// 간선과 그 비용을 저장하는 edge
tuple<int , int , int> edge[1000005];

// x 노드가 속한 그래프의 루트를 찾아서 리턴하는 함수
int Find(int x)
{
    if (p[x] < 0)
        return x;
    // 만약 p[x] >= 0 이라면
    // p[x] = Find(p[x]) 를 하고 p[x] 값을 리턴한다.
    return p[x] = Find(p[x]);
}

bool Union(int u , int v)
{
    // u, v 노드의 루트를 u,v에 초기화한다.
    u = Find(u);
    v = Find(v);
    // 만약 u,v 노드의 루트가 같다면 두 정점이 연결되어있다는 것이다.
    if (u == v)
        return false;
    // 이제 u,v 노드의 루트가 같지 않고 두 정점이 연결되어 있지 않다.
    // 따라서 두 노드가 포함된 트리를 합치는 과정을 시행한다.

    // 만약 u,v 의 밑에 있는 노드의 개수가 동일하다면
    if (p[u] == p[v])
        p[u]--; // u 노드 아래 있는 노드의 개수를 하나 늘린다.
    // 위의 if 문이 실행되었다면 이 if 문도 자동으로 실행이 된다.
    if (p[u] < p[v])
        p[v] = u; // v 노드의 부모 노드를 u 로 만든다.
    // 만약 u,v 의 밑에 있는 노드의 개수가 동일하지 않다면
    else
        p[u] = v; // u 노드의 부모 노드를 v 로 만든다.
    // 그리고 true 를 리턴한다.
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V;
    for (int i = 1;i <= V;i++)
        for (int j = 1;j <= V;j++)
        {
            int cost;
            cin >> cost;
            if (i >= j)
                continue;
            edge[E++] = { cost, i, j };
        }
    // 크루스칼 알고리즘을 사용한다.
    // 먼저 간선을 비용에 따른 오름차순으로 정렬한다.
    sort(edge , edge + E);
    // 사용하는 간선의 개수
    int cnt = 0;
    // 총 관리 비용
    long long result = 0;
    // 모든 간선을 탐색
    for (int i = 0;i < E;i++)
    {
        int a , b , cost;
        tie(cost , a , b) = edge[i];
        // 만약 두 정점이 연결되어 있다면 continue
        if (!Union(a , b))
            continue;
        result += cost;
        cnt++;
        if (cnt == V - 1)
            break;
    }
    cout << result;
}