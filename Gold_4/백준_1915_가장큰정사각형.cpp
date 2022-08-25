#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int N , M;
int DP[1005][1005];

int Max_Element()
{
    int max_result = 0;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < M;j++)
            max_result = max(max_result , DP[i][j]);
    return max_result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0;i < N;i++)
    {
        string s;
        cin >> s;
        for (int j = 0;j < s.length();j++)
            DP[i][j] = s[j] - '0';
    }
    // DP 를 이용한 가장 큰 정사각형의 크기를 구하는 알고리즘
    // DP[i][j] 는 i*j 크기 사각형에서 가장 큰 정사각형의 크기를 저장한다.
    // 만약 점이 존재한다면 그 점을 정사각형에 포함하는 정사각형의 크기를 저장한다.
    for (int i = 1;i < N;i++)
        for (int j = 1;j < M;j++)
            if (DP[i][j] != 0 && DP[i - 1][j - 1] != 0 && DP[i - 1][j] != 0 && DP[i][j - 1] != 0)
                DP[i][j] = min(DP[i - 1][j - 1] , min(DP[i - 1][j] , DP[i][j - 1])) + 1;
    int max_result = Max_Element();
    cout << max_result * max_result;
}