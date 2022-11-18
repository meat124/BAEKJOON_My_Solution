#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll result = 1e15;
vector<pair<int , int>> taste(12);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
        cin >> taste[i].first >> taste[i].second;
    for (int i = 1;i < (1 << N);i++)
    {
        ll s = 1 , b = 0;
        for (int j = 0;j < N;j++)
            if (i & (1 << j))
                s *= taste[j].first , b += taste[j].second;
        result = min(result , abs(s - b));
    }
    cout << result;
}