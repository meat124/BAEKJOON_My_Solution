#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int N , M;
string combi[105][105];

string Add_Num(string a , string b)
{
    if (a.length() > b.length())
        while (a.length() != b.length())
            b = '0' + b;
    else
        while (a.length() != b.length())
            a = '0' + a;
    string result = "";
    int sum = 0;
    for (int i = a.length() - 1;i >= 0;i--)
    {
        sum += (a[i] - '0') + (b[i] - '0');
        result = to_string(sum % 10) + result;
        if (sum >= 10)
            sum = 1;
        else
            sum = 0;
    }
    // 만약 자릿수가 올라갔으면
    if (sum)
        return '1' + result;
    return result;
}

string DFS(int n , int m)
{
    if (n == m || m == 0)
        return "1";
    string& result = combi[n][m];
    if (result != "")
        return result;
    result = Add_Num(DFS(n - 1 , m) , DFS(n - 1 , m - 1));
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    cout << DFS(N , M);
}