#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll , ll> pll;
pll a , b , c , d;

void Input()
{
    cin >> a.first >> a.second >> b.first >> b.second;
    cin >> c.first >> c.second >> d.first >> d.second;
}

// (p1 -> p2), (p1 -> p3) 벡터의 외적값을 리턴한다.
double CCW(pll p1 , pll p2 , pll p3)
{
    return (p2.first - p1.first) * (p3.second - p1.second) - (p3.first - p1.first) * (p2.second - p1.second);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Input();
    double abc = CCW(a , b , c) , abd = CCW(a , b , d) , cda = CCW(c , d , a) , cdb = CCW(c , d , b);

    if (abc * abd == 0 && cda * cdb == 0) // 4개의 점이 모두 같은 직선 위에 존재하는 경우
    {
        // a 보다 b 가 크고, c 보다 d 가 크게 맞춘다.
        if (a > b) swap(a , b);
        if (c > d) swap(c , d);

        if (a <= d && c <= b)
            cout << 1;
        else
            cout << 0;
    }
    else if (abc * abd <= 0 && cda * cdb <= 0) // 둘 다 음수이면 교차, 하나만 0이어도 다른 하나가 음수이면 교차
        cout << 1;
    else // 둘 다 양수이거나 하나는 0이고 하나는 양수인 경우 교차 x
        cout << 0;
}