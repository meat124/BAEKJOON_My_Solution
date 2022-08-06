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
    // start �� 0 ~ N - 1 ���� �����ϸ鼭 Ž���Ѵ�.
    for (int start = 0;start < N;start++)
    {
        // ���� end �� N ���� �۰�, ���̰� M ���� �۴ٸ�
        while (end < N && seq[end] - seq[start] < M)
            end++;
        if (end == N)
            break;
        result = min(result , seq[end] - seq[start]);
    }
    cout << result;
}