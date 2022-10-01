#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N;
vector<pair<ll , ll>> vertex;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (ll i = 0;i < N;i++)
    {
        ll x , y;
        cin >> x >> y;
        vertex.push_back({ x , y });
    }
    ll S1 = 0 , S2 = 0;
    for (ll i = 0;i < N - 1;i++)
    {
        S1 += vertex[i].first * vertex[i + 1].second;
        S2 += vertex[i].second * vertex[i + 1].first;
    }
    S1 += vertex.back().first * vertex.front().second;
    S2 += vertex.back().second * vertex.front().first;
    ll result = abs(S2 - S1);
    cout << result / 2 << ".";
    if (result % 2)
        cout << 5;
    else
        cout << 0;
}