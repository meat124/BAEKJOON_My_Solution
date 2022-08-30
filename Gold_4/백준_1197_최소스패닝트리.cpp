#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
// 라이브러리 추가 시에 tie 함수를 사용하는 경우 주의한다.
using namespace std;
// union by rank 의 구현
// p[i] 에 i 가 루트인 경우, rank 가 저장되고
// i 가 루트가 아닌 경우, i 의 부모가 저장되어 있다.
// 초기에는 모든 요소를 -1, 즉 루트이고, rank = 1 로 저장한다.
vector<int> p(10005 , -1);

int Find(int x)
{
    if (p[x] < 0)
        return x;
    return p[x] = Find(p[x]);
}

// union
bool Union(int u , int v)
{
    u = Find(u);
    v = Find(v);
    // 만약 루트가 같다면 false 리턴
    if (u == v)
        return false;
    // union by rank 를 위해서 코드를 나눈다.
    // 만약 u,v 가 속한 트리의 루트의 부모가 같다면?
    if (p[u] == p[v])
        p[u]--;
    // 만약 u가 속한 트리의 부모가 v가 속한 트리의 부모보다 작다면
    if (p[u] < p[v])
        p[v] = u;
    // 만약 u가 속한 트리의 부모가 v가 속한 트리의 부모보다 크다면
    else
        p[u] = v;
    return true;
}
int V , E;
tuple<int , int , int> edge[100005];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> V >> E;
    for (int i = 0;i < E;i++)
    {
        int a , b , cost;
        cin >> a >> b >> cost;
        edge[i] = { cost, a, b }; // cost 기준으로 오름차순 정렬을 위해 첫 번째 요소로 초기화
    }
    sort(edge , edge + E);
    int cnt = 0;
    int ans = 0;
    for (int i = 0;i < E;i++)
    {
        int a , b , cost;
        tie(cost , a , b) = edge[i];
        if (!Union(a , b))
            continue;
        ans += cost;
        cnt++;
        if (cnt == V - 1)
            break;
    }
    cout << ans;
}