#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> DP(1001);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str1 , str2;
    cin >> str1 >> str2;

    for (int i = 0;i < str1.length();i++)
    {
        int cnt = 0;
        for (int j = 0;j < str2.length();j++)
        {
            if (cnt < DP[j])
                cnt = DP[j];
            else if (str1[i] == str2[j])
                DP[j] = cnt + 1;
        }
    }
    cout << *max_element(DP.begin() , DP.end());
}