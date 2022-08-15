#include<iostream>
#include<string>
using namespace std;
string str1 , str2;
// DP[i][j] = DP[i - 1][j - 1] + 1
int DP[5000][5000];
int max_len = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> str1;
    cin >> str2;
    int str1_len = str1.length();
    int str2_len = str2.length();
    // O(N^2)
    for (int i = 0;i < str2_len;i++)
        for (int j = 0;j < str1_len;j++)
            if (str2[i] == str1[j])
            {
                DP[i][j] = 1; // 일단 일치하므로 1 대입
                // 만약 경계값이 아니라면 이전 DP 값 합 연산
                if (i >= 1 && j >= 1)
                    DP[i][j] += DP[i - 1][j - 1];
                max_len = max(max_len , DP[i][j]);
            }
    cout << max_len;
}