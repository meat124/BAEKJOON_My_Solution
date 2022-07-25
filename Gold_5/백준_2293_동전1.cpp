#include<iostream>
#include<vector>
using namespace std;
int N , K;
vector<int> value;
// DP[i] 는 i 원을 만들 수 있는 경우의 수
int DP[10001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    for (int i = 0;i < N;i++)
    {
        int n;
        cin >> n;
        value.push_back(n);
    }
    DP[0] = 1;
    for (auto v : value)
        for (int i = v;i <= K;i++)
            DP[i] += DP[i - v];

    cout << DP[K];
}