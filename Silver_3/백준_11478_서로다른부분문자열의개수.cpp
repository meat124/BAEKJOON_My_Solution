#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
string S;
unordered_set<string> sub_str;
// 문자열의 길이가 N 일 때
// 길이 1인 부분 = N
// 길이 2인 부분 = N - 1
// 길이 3인 부분 = N - 2
// 길이 N인 부분 = 1
// 따라서 빅오표기법을 따르면 시간 복잡도는 O(N^2)
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> S;
    for (int i = 1;i <= S.length();i++)
        for (int j = 0;j <= S.length() - i;j++)
            sub_str.insert(S.substr(j , i));
    cout << sub_str.size();
}