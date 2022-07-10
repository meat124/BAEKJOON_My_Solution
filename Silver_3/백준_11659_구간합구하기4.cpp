#include <iostream>
using namespace std;
int arr[100002];
int DP[100002]; // DP[i] 는 arr[1] ~ arr[i] 까지의 합

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;
    for (size_t i = 1; i <= N; i++)
        cin >> arr[i];
    DP[0] = 0;
    DP[1] = arr[1];
    for (size_t i = 2; i <= N; i++)
    {
        DP[i] = DP[i - 1] + arr[i];
    }
    pair<int, int> tmp;
    for (size_t i = 0; i < M; i++)
    {
        cin >> tmp.first >> tmp.second;
        cout << DP[tmp.second] - DP[tmp.first - 1] << "\n";
    }
}