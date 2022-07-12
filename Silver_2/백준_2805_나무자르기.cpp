#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M;
vector<int> height;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int n;
        cin >> n;
        height.push_back(n);
    }
    int start = 0;
    int end = *max_element(height.begin(), height.end());
    int result = 0;

    while (start <= end)
    {
        long long total = 0;
        int mid = (start + end) / 2;
        for (int i = 0; i < N; i++)
            if (height[i] > mid)
                total += (height[i] - mid);
        if (total < M)
            end = mid - 1;
        else
        {
            result = mid;
            start = mid + 1;
        }
    }
    cout << result;
}