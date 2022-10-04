#include<bits/stdc++.h>
using namespace std;
string str1 , str2;
int DP[1005][1005]; // DP[i] 는 i 번째 문자열까지에서 LCS 의 길이를 저장한다.

void Tracked_LCS(int i , int j)
{
    if (DP[i][j] == 0)
        return;
    if (str1[i - 1] == str2[j - 1])
    {
        Tracked_LCS(i - 1 , j - 1);
        cout << str1[i - 1]; // str1[i - 1] == str2[j - 1] 이므로 아무거나 출력
    }
    else
        DP[i - 1][j] >= DP[i][j - 1] ? Tracked_LCS(i - 1 , j) : Tracked_LCS(i , j - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> str1 >> str2;

    for (int i = 1;i <= str1.size();i++)
        for (int j = 1;j <= str2.size();j++)
            if (str1[i - 1] == str2[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j] , DP[i][j - 1]);

    cout << DP[str1.size()][str2.size()] << "\n";
    Tracked_LCS(str1.size() , str2.size());
}