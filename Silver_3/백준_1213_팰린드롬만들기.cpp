#include<iostream>
#include<string>
#include<deque>
using namespace std;
string name;
int char_cnt[30]; // 알파벳 나온 횟수
deque<char> palindrome;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> name;

    for (int i = 0;i < name.length();i++)
        char_cnt[name[i] - 'A']++;
    int odd_cnt = 0; // 홀수 번 등장한 알파벳 개수
    char odd_char;
    for (int i = 0;i < 26;i++)
        if (char_cnt[i] % 2 == 1)
        {
            odd_cnt++;
            odd_char = i + 'A';
        }
    if (odd_cnt > 1)
    {
        cout << "I'm Sorry Hansoo\n";
        return 0;
    }
    else if (odd_cnt == 1)
    {
        palindrome.push_back(odd_char);
        char_cnt[odd_char - 'A']--;
    }

    for (int i = 25;i >= 0;i--)
        while (char_cnt[i] != 0 && char_cnt[i] % 2 == 0)
        {
            palindrome.push_back(i + 'A');
            palindrome.push_front(i + 'A');
            char_cnt[i] -= 2;
        }
    for (auto i : palindrome)
        cout << i;
    cout << "\n";
    return 0;
}