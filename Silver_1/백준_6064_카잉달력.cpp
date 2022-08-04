#include<iostream>
using namespace std;
int M , N;
int x , y;

// 유클리드 호제법 사용
// a < b
int GCD(int a , int b)
{
    if (a == 0) return b;
    return GCD(b % a , a);
}

int LCM(int a , int b)
{
    // a * b = LCM * GCD 임을 활용
    return a / GCD(a , b) * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> M >> N >> x >> y;
        bool flag = true;
        if (x == M) x = 0;
        if (y == N) y = 0;
        int lcm = LCM(M , N);
        for (int i = x;i <= lcm; i += M)
        {
            if (i == 0)
                continue;
            if (i % N == y)
            {
                cout << i << "\n";
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "-1\n";
    }
}