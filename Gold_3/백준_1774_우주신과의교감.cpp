#include<bits/stdc++.h>
using namespace std;
int V , E;
vector<int> p(1005 , -1);
pair<int , int> vertex[1005];
// cost, departure_node_num, arrival_node_num
tuple<double , int , int> edge[1000005];
bool connected_edge[1005][1005];

// 노드 번호를 인자로 받아서 그 노드가 속한 트리의 루트 노드의 번호를 리턴한다.
int Find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = Find(p[x]);
}

// 노드 번호 두 개를 인자로 받아서 두 노드가 속한 트리의 노드 개수를 비교한다.
bool Union(int u , int v)
{
    u = Find(u);
    v = Find(v);
    // 만약 서로 같은 집합 안에 있다면
    if (u == v)
        return false;
    // 서로 다른 집합이고 u 트리의 크기가 v 트리의 크기보다 크다면
    if (p[u] <= p[v])
    {
        p[u] += p[v];
        p[v] = u;
    }
    // 서로 다른 집합이고 v 트리의 크기가 u 트리의 크기보다 크다면
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
    // 노드 개수, 이미 존재하는 간선 개수
    cin >> V >> E;
    // 노드 좌표 입력
    for (int i = 1;i <= V;i++)
    {
        int a , b;
        cin >> a >> b;
        // i 번 노드의 좌표는 {a,b}
        vertex[i] = { a,b };
    }
    // 이미 존재하는 간선 입력
    for (int i = 0;i < E;i++)
    {
        int a , b;
        cin >> a >> b;
        // a 번 노드에서 b 번 노드로 가는 간선 이미 존재
        connected_edge[a][b] = true;
        Union(a , b);
    }
    int n = 0;
    for (int i = 1;i <= V;i++)
        for (int j = i + 1;j <= V;j++)
        {
            if (connected_edge[i][j])
                continue;
            double cost = sqrt(pow(abs(vertex[j].first - vertex[i].first) , 2) + pow(abs(vertex[j].second - vertex[i].second) , 2));
            // i 번 노드에서 j 번 노드로 가는 비용이 cost인 간선 추가
            edge[n++] = { cost, i, j };
        }
    sort(edge , edge + n);

    int cnt = E;
    double result = 0;
    for (int i = 0;i < n;i++)
    {
        double cost;
        int start , end;
        tie(cost , start , end) = edge[i];
        if (!Union(start , end))
            continue;
        cnt++;
        result += cost;
        if (cnt == V - 1)
            break;
    }
    cout << fixed;
    cout.precision(2);
    cout << result;
}