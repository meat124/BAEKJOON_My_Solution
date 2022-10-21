#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 55;
ll result;
ll A , B;
ll digit_cnt[MAX]; // 이진수의 자릿수의 1의 총 개수

ll Solve(ll n)
{
    ll cnt = n & 1;
    for (int i = MAX - 1;i > 0;i--)
        if (n & (1LL << i)) // (1LL << i) == 2^i 이고 이는 n 의 최고 비트부터 검사한다.
        {
            // digit_cnt[i - 1] 는 i - 1 번째 비트까지의 1의 개수
            // (n - (1LL << i) + 1) 은 i 번 비트의 값을 빼주고 i 번 비트가 1이므로 그것을 1을 더해줘서 구한다.
            cnt += digit_cnt[i - 1] + (n - (1LL << i) + 1);
            n -= 1LL << i; // 최고 비트의 값을 제거해서 다음 최고 비트로 넘어가게 한다.
        }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B;

    digit_cnt[0] = 1;
    for (int i = 1;i < MAX;i++)
        digit_cnt[i] = 2 * digit_cnt[i - 1] + (1LL << i);

    result = Solve(B) - Solve(A - 1);
    cout << result;
}