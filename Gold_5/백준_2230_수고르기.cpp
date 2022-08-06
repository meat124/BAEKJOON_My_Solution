#include<iostream>
#include<algorithm>
using namespace std;
int N , M;
int seq[100005];
int result = 0x7FFFFFFF;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < N;i++)
        cin >> seq[i];
    sort(seq , seq + N);
    // 이 값을 넘기면 더 이상 계산x
    int max_num = seq[N - 1] - M;
    for (int i = 0;i < N;i++)
    {
        if (seq[i] > max_num)
            break;
        // seq[i] + M 보다 크거나 같은 값이 나타나는 첫 지점의 iterator 를 리턴한다.
        result = min(result , seq[lower_bound(seq , seq + N , seq[i] + M) - seq] - seq[i]);
    }
    cout << result;
}