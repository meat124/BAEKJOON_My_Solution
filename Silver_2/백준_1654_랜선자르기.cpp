#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int K , N;
vector<int> lan;
// 이분 탐색 활용
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> K >> N;
    for (int i = 0; i < K; i++)
    {
        int tmp;
        cin >> tmp;
        lan.push_back(tmp);
    }
    long long start = 1;
    long long end = *max_element(lan.begin() , lan.end());
    int max_len = 1;
    while (start <= end)
    {
        long long mid = (start + end) / 2;
        int cnt = 0;
        for (int i = 0; i < K; i++)
            cnt += lan[i] / mid;
        if (N <= cnt)
        {
            max_len = max_len > mid ? max_len : mid;
            start = mid + 1;
        }
        else // 만약 개수가 적다면 길이를 줄여야 한다.
            end = mid - 1;
    }
    cout << max_len;
}