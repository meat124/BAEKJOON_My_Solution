#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N , M , K;
const ll MAX = 1e6;
ll num[MAX];
ll prefix_sum[4 * MAX];

ll Prefix_Sum_Tree_Init(ll st , ll en , ll n)
{
    if (st == en)
        return prefix_sum[n] = num[st];
    ll mid = (st + en) / 2;
    return prefix_sum[n] = Prefix_Sum_Tree_Init(st , mid , 2 * n) + Prefix_Sum_Tree_Init(mid + 1 , en , 2 * n + 1);
}

ll Prefix_Sum(ll st , ll en , ll n , ll l , ll r)
{
    if (st > r || en < l)
        return 0;
    if (st >= l && en <= r)
        return prefix_sum[n];
    ll mid = (st + en) / 2;
    return Prefix_Sum(st , mid , 2 * n , l , r) + Prefix_Sum(mid + 1 , en , 2 * n + 1 , l , r);
}

void Prefix_Update(ll st , ll en , ll n , ll idx , ll val)
{
    if (idx < st || en < idx)
        return;
    prefix_sum[n] += val;
    if (st == en)
        return;
    ll mid = (st + en) / 2;
    Prefix_Update(st , mid , 2 * n , idx , val);
    Prefix_Update(mid + 1 , en , 2 * n + 1 , idx , val);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> K;
    for (ll i = 0;i < N;i++)
        cin >> num[i];
    Prefix_Sum_Tree_Init(0 , N - 1 , 1);
    for (ll i = 0;i < M + K;i++)
    {
        ll a , b , c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            ll tmp = c - num[b - 1];
            num[b - 1] = c;
            Prefix_Update(0 , N - 1 , 1 , b - 1 , tmp);
        }
        else if (a == 2)
            cout << Prefix_Sum(0 , N - 1 , 1 , b - 1 , c - 1) << "\n";
    }
}
