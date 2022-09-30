#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int M , N , S;
ll result = 0;

ll Cal_Inverse(ll b)
{
    // b^(MOD - 2) 의 값을 리턴한다.
    ll ret = 1;
    ll indices = MOD - 2;
    while (indices)
    {
        if (indices & 1)
            ret = ret * b % MOD;
        indices /= 2;
        b = b * b % MOD;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> M;
    for (int i = 0;i < M;i++)
    {
        cin >> S >> N;
        result += (N * (Cal_Inverse(S))) % MOD;
    }
    cout << result % MOD;
}