#include<iostream>
using namespace std;
int n;
int arr[10002];
int DP[10002]; // DP[i] 는 arr[i] 까지 마실 수 있는 최대의 포도주

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1;i <= n;i++)
        cin >> arr[i];
    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];
    DP[3] = max(max(arr[1] + arr[3] , arr[2] + arr[3]) , arr[1] + arr[2]);
    // DP[i] = DP[i - 2] + arr[i] 와 DP[i - 3] + arr[i - 1] + arr[i]
    // 그리고 무조건 마지막 잔을 고르라는 말이 없으므로 DP[i] = DP[i - 1] 인 경우도 고려
    for (int i = 4;i <= n;i++)
        DP[i] = max(max(DP[i - 2] + arr[i] , DP[i - 3] + arr[i - 1] + arr[i]) , DP[i - 1]);
    cout << max(DP[n - 1] , DP[n]);
}