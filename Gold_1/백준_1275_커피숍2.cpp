#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N , Q;
ll A[100005];
ll tree[400005]; // 데이터의 개수가 최대 10만이므로 트리의 크기는 40만으로 잡는다.

ll init(int st , int en , int node)
{
    if (st == en)
        return tree[node] = A[st];
    int mid = (st + en) / 2;
    return tree[node] = init(st , mid , node * 2) + init(mid + 1 , en , node * 2 + 1);
}

ll sum(int st , int en , int node , int l , int r)
{
    if (st > r || en < l)
        return 0;
    if (st >= l && en <= r)
        return tree[node];
    int mid = (st + en) / 2;
    return sum(st , mid , node * 2 , l , r) + sum(mid + 1 , en , node * 2 + 1 , l , r);
}

void update(int st , int en , int node , int idx , ll d)
{
    if (st > idx || en < idx)
        return;
    tree[node] += d;
    if (st == en)
        return;
    int mid = (st + en) / 2;
    update(st , mid , node * 2 , idx , d);
    update(mid + 1 , en , node * 2 + 1 , idx , d);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 0;i < N;i++)
        cin >> A[i];
    init(0 , N - 1 , 1);
    for (int i = 0;i < Q;i++)
    {
        ll x , y , a , b;
        cin >> x >> y >> a >> b;
        if (x > y)
            swap(x , y);
        cout << sum(0 , N - 1 , 1 , x - 1 , y - 1) << "\n";
        ll tmp = b - A[a - 1];
        A[a - 1] = b;
        update(0 , N - 1 , 1 , a - 1 , tmp);
    }
}