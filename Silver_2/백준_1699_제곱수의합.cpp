#include<iostream>
using namespace std;
int N;
int DP[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;

    // DP[i] 는 i 를 제곱수 합으로 표현할 수 있는 항의 최소 개수
    // i - 1^2, i - 2^2, i - 3^2, ... , i - k^2 >= 0 까지 진행하여 최소 값을 찾는다.
    // O(Nsqrt(N)) = 10^5*316 = 3*10^7 = 3천만
    fill(DP , DP + N + 1 , 0x7FFFFFFF);
    DP[0] = 1;
    DP[1] = 1;
    for (int i = 2;i <= N;i++)
    {
        int k = 1;
        int tmp = 1;
        while ((i - (tmp * tmp)) >= 0)
        {
            if (i - (tmp * tmp) == 0)
                DP[i] = 1;
            else
                DP[i] = min(DP[i - (tmp * tmp)] + 1 , DP[i]);
            tmp++;
        }
    }
    cout << DP[N];
}