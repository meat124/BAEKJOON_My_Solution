#include <iostream>
using namespace std;

using ll = long long;

// 시간 복잡도 O(log n)
ll Pow(ll a, ll b, ll c)
{
    if (b == 1)
        return a % c;
    ll val = Pow(a, b / 2, c); // 만약 b 가 짝수이면 그대로 전달, 홀수라면 1이 빠진 채로 전달
    val = val * val % c;       // 2^2k = 2^k * 2^k
    if (b % 2 == 0)            // 만약 b 가 짝수였다면 그대로 사용
        return val;
    return val * a % c; // 만약 b 가 홀수라면 a 가 하나 빠졌으므로 곱해주고 나머지를 리턴
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll A, B, C;
    cin >> A >> B >> C;

    cout << Pow(A, B, C);
}