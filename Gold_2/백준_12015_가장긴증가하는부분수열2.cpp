#include<bits/stdc++.h>
using namespace std;
const int MAX = 1000005;
int N;
vector<int> LIS = { MAX };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1;i <= N;i++)
    {
        int A;
        cin >> A;
        if (A > LIS.back())
            LIS.push_back(A);
        else
        {
            int idx = lower_bound(LIS.begin() , LIS.end() , A) - LIS.begin(); // A 와 같거나 큰 수가 처음으로 나타나는 위치
            LIS[idx] = A;
        }
    }
    cout << LIS.size();
}