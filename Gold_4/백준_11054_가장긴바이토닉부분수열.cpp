#include<iostream>
using namespace std;
int N;
int seq[1005];
// DP_asc[i][0] 는 seq[i] 까지 증가하는 최대 부분집합 길이
// DP_asc[i][1] 는 순열의 마지막 값
int DP_asc[1005][2];
// DP_des[i][0] 는 seq[i] ~ seq[N] 까지 감소하는 최대 부분집합 길이
// DP_des[i][1] 는 순열의 시작 값
int DP_des[1005][2];
int max_len = 0;
int max_asc = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 1;i <= N;i++)
        cin >> seq[i];
    if (N == 1)
    {
        cout << 1;
        return 0;
    }
    // 감소 DP 와 증가 DP 를 각각 구한 뒤, 그 합이 최대가 되는 지점을 찾는다.
    DP_asc[1][0] = 1 , DP_asc[1][1] = seq[1];
    for (int i = 2;i <= N;i++)
    {
        DP_asc[i][0] = 1 , DP_asc[i][1] = seq[i];
        for (int j = 1;j < i;j++)
            if (DP_asc[j][1] < DP_asc[i][1] && DP_asc[i][0] < DP_asc[j][0] + 1) // 증가한다면
            {
                DP_asc[i][0] = DP_asc[j][0] + 1;
                DP_asc[i][1] = seq[i];
            }
        max_asc = max(max_asc , DP_asc[i][0]);
    }
    DP_des[N][0] = 1 , DP_des[N][1] = seq[N];
    for (int i = N - 1;i >= 1;i--)
    {
        DP_des[i][0] = 1 , DP_des[i][1] = seq[i];
        for (int j = N;j > i;j--)
            if (DP_des[j][1] < DP_des[i][1] && DP_des[i][0] < DP_des[j][0] + 1)
            {
                DP_des[i][0] = DP_des[j][0] + 1;
                DP_des[i][1] = seq[i];
            }
    }
    for (int i = 1;i <= N;i++)
        for (int j = i;j <= N;j++)
            if (DP_asc[i][1] > DP_des[j][1])
                max_len = max(max_len , DP_asc[i][0] + DP_des[j][0]);
    if (max_len == 0)
        cout << max_asc;
    else
        cout << max_len;
}