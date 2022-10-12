#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll liq[5005]; // 용액의 특성값을 저장
ll result_value[3];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
        cin >> liq[i];
    sort(liq , liq + N);

    ll result = 10000000000;

    for (int i = 0;i < N - 2;i++)
    {
        int st = i + 1 , en = N - 1;
        while (st < en)
        {
            ll tmp = liq[i] + liq[st] + liq[en];
            if (abs(tmp) < result)
            {
                result = abs(tmp);
                result_value[0] = liq[i] , result_value[1] = liq[st] , result_value[2] = liq[en];
            }
            if (tmp < 0)
                st++;
            else
                en--;
        }
    }
    for (int i = 0;i < 3;i++)
        cout << result_value[i] << " ";
}