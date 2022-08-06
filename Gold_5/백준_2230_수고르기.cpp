#include<iostream>
#include<algorithm>
using namespace std;
int N , M;
int seq[100005];
int result = 0x7fffffff;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < N;i++)
        cin >> seq[i];
    sort(seq , seq + N);
    int end = 0;
    // start 가 0 ~ N - 1 까지 증가하면서 탐색한다.
    for (int start = 0;start < N;start++)
    {
        // 만약 end 가 N 보다 작고, 차이가 M 보다 작다면
        while (end < N && seq[end] - seq[start] < M)
            end++;
        if (end == N)
            break;
        result = min(result , seq[end] - seq[start]);
    }
    cout << result;
}