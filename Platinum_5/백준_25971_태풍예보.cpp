#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct coord
{
    ll n , x , y;
    coord(ll n , ll x , ll y) : n(n) , x(x) , y(y) {}
};
ll N , K , R , Q;
string result[3] = { "gori\n", "safe\n", "unsafe\n" };
vector<coord> S;

bool Is_In(coord& h)
{
    ll dx = abs(S[h.n].x - h.x) , dy = abs(S[h.n].y - h.y);
    if (dx * dx + dy * dy <= R * R)
        return true;
    return false;
}

int Is_Danger(coord& h)
{
    pair<ll , ll> s_path , h_path;
    if (h.n != N)
        s_path = { S[h.n + 1].x - S[h.n].x, S[h.n + 1].y - S[h.n].y };
    else
        s_path = { S[h.n].x - S[h.n - 1].x, S[h.n].y - S[h.n - 1].y };
    h_path = { h.x - S[h.n].x, h.y - S[h.n].y };
    ll external_product = s_path.first * h_path.second - s_path.second * h_path.first;
    // 0 이면 경계, 양수이면 안전, 음수이면 위험
    return external_product;
}

int Solve(coord& h)
{
    // 사람이 현재 안전반원, 위험반원, 경계 또는 밖인지 구분한다.
    int flag = Is_Danger(h);
    if (!Is_In(h))
        return 0;
    else if (flag == 0)
        return 0;
    else if (flag > 0)
        return 1;
    else
        return 2;
    // 태풍 방향에 따라서 안전,위험 반원의 위치가 달라진다는 점 고려해야함
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K >> R >> Q;
    S.push_back(coord(0 , 0 , 0));
    for (int i = 0; i < K; i++)
    {
        ll n , x , y;
        cin >> n >> x >> y;
        if (n != 1)
        {
            ll dx = (x - S.back().x) / (n - S.back().n);
            ll dy = (y - S.back().y) / (n - S.back().n);
            ll nx = S.back().x + dx , ny = S.back().y + dy;
            for (ll j = S.back().n + 1; j < n; j++)
            {
                S.push_back(coord(j , nx , ny));
                nx += dx , ny += dy;
            }
        }
        S.push_back(coord(n , x , y));
    }
    for (int i = 0; i < Q; i++)
    {
        ll n , x , y;
        cin >> n >> x >> y;
        coord c(n , x , y);
        cout << result[Solve(c)];
    }
}
