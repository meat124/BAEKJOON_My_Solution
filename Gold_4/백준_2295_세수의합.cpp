#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector<int> set;
vector<int> two_sum_set;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        int n;
        cin >> n;
        set.push_back(n);
    }
    sort(set.begin() , set.end()); // O(NlogN)
    // O(N^2)
    // 2���� ���ų�, ��� �� ���� ���� �̺� Ž������ ã�Ƽ� �ð� ���⵵�� �����.
    for (int i = 0;i < N;i++)
        for (int j = i;j < N;j++)
            two_sum_set.push_back(set[i] + set[j]);
    sort(two_sum_set.begin() , two_sum_set.end());
    // set, two_sum_set ��� �������� ���ĵ� ����
    int two_size = two_sum_set.size();
    for (int i = N - 1;i > 0;i--)
        for (int j = 0;j < i;j++)
            if (binary_search(two_sum_set.begin() , two_sum_set.end() , set[i] - set[j]))
            {
                // set[i] > set[j]
                cout << set[i];
                return 0;
            }
}