#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool desc(string a, string b)
{
    return a.length() < b.length();
}

bool compare_lib(string a, string b)
{
    // 좌변은 문자열의 길이가 서로 같으면 1 을 리턴
    // 우변은 문자열이 현재 사전순 정렬이면 1 을 리턴
    // 둘 다 1을 리턴한 경우, AND 연산으로 1을 리턴해서 true
    return (a.length() == b.length() && a < b);
}

int main()
{
    int n;
    cin >> n;

    vector<string> str(n);

    for (int i = 0; i < n; i++)
        cin >> str[i];
    // 길이에 따른 내림차순 정렬
    sort(str.begin(), str.end(), desc);

    // 길이가 같은 문자열끼리 사전순 정렬
    // 기존에 sort 로 하면 반례 발생으로 틀림 > stable_sort 로 변경해서 성공
    stable_sort(str.begin(), str.end(), compare_lib);

    for (int i = 0; i < str.size(); i++)
    {
        // 중복 문자열 처리
        if (i != 0 && str[i - 1] == str[i])
            continue;
        cout << str[i] << endl;
    }
}