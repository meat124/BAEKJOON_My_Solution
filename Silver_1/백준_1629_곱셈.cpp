#include <iostream>
using namespace std;

using ll = long long;

// �ð� ���⵵ O(log n)
ll Pow(ll a, ll b, ll c)
{
    if (b == 1)
        return a % c;
    ll val = Pow(a, b / 2, c); // ���� b �� ¦���̸� �״�� ����, Ȧ����� 1�� ���� ä�� ����
    val = val * val % c;       // 2^2k = 2^k * 2^k
    if (b % 2 == 0)            // ���� b �� ¦�����ٸ� �״�� ���
        return val;
    return val * a % c; // ���� b �� Ȧ����� a �� �ϳ� �������Ƿ� �����ְ� �������� ����
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll A, B, C;
    cin >> A >> B >> C;

    cout << Pow(A, B, C);
}