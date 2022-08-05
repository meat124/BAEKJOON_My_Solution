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
    // 2개를 묶거나, 어느 한 쪽의 값을 이분 탐색으로 찾아서 시간 복잡도를 낮춘다.
    for (int i = 0;i < N;i++)
        for (int j = i;j < N;j++)
            two_sum_set.push_back(set[i] + set[j]);
    sort(two_sum_set.begin() , two_sum_set.end());
    // set, two_sum_set 모두 오름차순 정렬된 상태
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