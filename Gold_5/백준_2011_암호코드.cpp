#include<iostream>
#include<string>
using namespace std;
string pwd;
int DP[5005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> pwd;
    int len = pwd.length();
    DP[0] = 1;
    pwd = " " + pwd; // 첫번째 원소를 공백으로 만듦
    for (int i = 1;i <= len;i++)
    {
        int cur = pwd[i] - '0'; // 현재 보고있는 번호
        if (cur != 0)
            DP[i] = DP[i - 1] % 1000000;
        if (i == 1 || pwd[i - 1] == '0')
            continue;
        cur = 10 * (pwd[i - 1] - '0') + (pwd[i] - '0');
        if (cur >= 10 && cur <= 26)
            DP[i] = (DP[i] + DP[i - 2]) % 1000000;
    }
    cout << DP[len];
}