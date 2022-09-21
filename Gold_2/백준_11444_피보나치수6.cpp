#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long n;
typedef vector<vector<long long>> matrix;
matrix operator*(matrix& a , matrix& b)
{
    matrix tmp(2 , vector<long long>(2));

    for (int i = 0;i < 2;i++)
        for (int j = 0;j < 2;j++)
        {
            for (int k = 0;k < 2;k++)
                tmp[i][j] += a[i][k] * b[k][j];
            tmp[i][j] %= MOD;
        }
    return tmp;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    // 분할 정복을 이용한 거듭제곱
    // {1,1,1,0} 을 곱하면 피보나치 다음 수열이 나온다.
    matrix result = { {1,0}, {0,1} };
    matrix multiply = { {1,1}, {1,0} };

    while (n)
    {
        if (n % 2)
            result = result * multiply;
        multiply = multiply * multiply;
        n /= 2;
    }
    cout << result[0][1];
}