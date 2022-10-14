#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T , n , m;
ll result; // 가능한 경우의 수
int A[1005] , B[1005];
vector<ll> sum_A , sum_B;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    cin >> n;
    for (int i = 0;i < n;i++)
        cin >> A[i];
    cin >> m;
    for (int i = 0;i < m;i++)
        cin >> B[i];
    // A 배열에 대한 모든 부분합 저장
    for (int i = 0;i < n;i++)
    {
        ll sum = A[i];
        sum_A.push_back(sum);
        for (int j = i + 1;j < n;j++)
        {
            sum += A[j];
            sum_A.push_back(sum);
        }
    }
    // B 배열에 대한 모든 부분합 저장
    for (int i = 0;i < m;i++)
    {
        ll sum = B[i];
        sum_B.push_back(sum);
        for (int j = i + 1;j < m;j++)
        {
            sum += B[j];
            sum_B.push_back(sum);
        }
    }
    sort(sum_A.begin() , sum_A.end()); // 개수 n^2/2
    sort(sum_B.begin() , sum_B.end()); // 개수 m^2/2
    // 정렬 완료
    // 크기순으로 정렬된 부분합에서 그 합이 서로 T 가 되는 것을 찾아서 그 경우의 수를 세면된다.
    // 브루트포스 불가능 >> 2500억
    // 따라서 이분 탐색으로 그 값을 추정한다.
    for (auto i : sum_A)
    {
        ll value = T - i;
        int cnt = upper_bound(sum_B.begin() , sum_B.end() , value) - lower_bound(sum_B.begin() , sum_B.end() , value);
        result += cnt;
    }
    cout << result;
}