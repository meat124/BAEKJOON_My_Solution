#include<bits/stdc++.h>
using namespace std;
int V , E;
vector<int> p(305 , -1);
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

    cin >> V;
    for (int i = 1;i <= V;i++)
    {
        int cost;
        cin >> cost;
        // 우물을 파는 비용은 V + 1 번째 논과 연결하는 상황이라고 가정
        // 그러면 전체적으로 최소 신장 트리가 된다.
        edge[E++] = { cost, i, V + 1 };
    }
    // 입력은 주대각선 대칭 형태이므로 if 문을 추가해서 중복은 무시한다.
    for (int i = 1;i <= V;i++)
        for (int j = 1;j <= V;j++)
        {
            int cost;
            cin >> cost;
            if (i >= j)
                continue;
            // { 비용, 시작점, 도착점 }
            edge[E++] = { cost, i, j };
        }
    V++; // 가상의 우물을 파는 비용을 연결하는 정점을 넣기 위해 1증가
    sort(edge , edge + E);
    int cnt = 0;
    int result = 0;
    for (int i = 0;i < E;i++)
    {
        int a , b , cost;
        // cost, a, b 에 edge[i] 에 있던 값으로 초기화
        tie(cost , a , b) = edge[i];
        if (!Union(a , b))
            continue;
        result += cost;
        cnt++;
        // 간선의 개수가 V - 1 개가 되어서 모두 연결이 되었다면 종료
        if (cnt == V - 1)
            break;
    }
    cout << result;
}