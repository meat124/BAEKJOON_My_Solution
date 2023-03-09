#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 5;
int N , M;
vector<int> p(MAX , -1);
int Find(int x)
{
    // 노드 x 가 어느 집합에 포함되어 있는지 찾는 알고리즘
    // x가 속한 트리의 루트를 리턴한다.
    if (p[x] < 0)
        return x;
    return p[x] = Find(p[x]);
}
bool Union(int u , int v)
{
    // 노드 u,v가 포함된 집합을 서로 합치는 알고리즘
    u = Find(u);
    v = Find(v);
    // 만약 두 노드의 루트가 같다면 false 리턴한다.
    // 같다는 것은 사이클이 발생한다는 것
    if (u == v)
        return false;
    // u,v는 각각 루트이고, 따라서 p[u],p[v] 의 값은 음수이다.
    // 이때 음수의 절대값이 크면 크기가 더 큰 집합이다.
    if (p[u] < p[v])
    {
        p[u] += p[v]; // 크기가 큰 집합에 합치고
        p[v] = u; // 크기가 작은 집합의 루트를 큰 집합의 루트로 변경함
    }
    else
    {
        p[v] += p[u];
        p[u] = v;
    }
    return true;
}
tuple<int , int , int> edge[MAX];
// 성사되었으면 true, 아니면 false
bool Is_Real[10005][10005];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < M;i++)
    {
        int a , b , c , d;
        cin >> a >> b >> c >> d;
        // 애정도인 c 를 가장 앞에 두고 저장한다.
        edge[i] = { c,a,b };
        if (d)
        {
            Is_Real[a][b] = Is_Real[b][a] = true;
            Union(a , b);
        }
    }
    // 애정도를 기준으로 내림차순으로 정렬한다.
    sort(edge , edge + M , greater<>());
    int result = 0;
    // 이제 애정도가 낮은 순서대로 보면서 루프를 이루고 있다면 제거하면 된다.
    for (int i = 0;i < M;i++)
    {
        int c , a , b;
        tie(c , a , b) = edge[i];
        // 만약 성사된 관계라면 건드리지 않는다.
        if (Is_Real[a][b])
            continue;
        // 루프를 이루고 있는지 확인하는 방법?
        if (!Union(a , b))
        {
            result += c;
            continue;
        }
    }
    cout << result;
}