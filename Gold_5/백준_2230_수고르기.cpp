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
    // �� ���� �ѱ�� �� �̻� ���x
    int max_num = seq[N - 1] - M;
    for (int i = 0;i < N;i++)
    {
        if (seq[i] > max_num)
            break;
        // seq[i] + M ���� ũ�ų� ���� ���� ��Ÿ���� ù ������ iterator �� �����Ѵ�.
        result = min(result , seq[lower_bound(seq , seq + N , seq[i] + M) - seq] - seq[i]);
    }
    cout << result;
}