#include<bits/stdc++.h>
using namespace std;
string notation;
stack<char> S;

bool Is_Alpha(char& c)
{
    if (c >= 'A' && c <= 'Z')
        return true;
    return false;
}

int Priority(char& c)
{
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    else
        return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> notation;
    for (int i = 0;i < notation.length();i++)
    {
        // 만약 value 일 경우
        if (Is_Alpha(notation[i]))
            cout << notation[i];
        // 괄호인 경우
        else if (notation[i] == '(')
            S.push(notation[i]);
        else if (notation[i] == ')')
        {
            // 여는 괄호를 만날 때 까지 연산자 출력하고 팝
            while (S.top() != '(')
            {
                cout << S.top();
                S.pop();
            }
            S.pop(); // 남아있는 '(' 팝
        }
        // 연산자인 경우
        else
        {
            while (!S.empty() && Priority(S.top()) >= Priority(notation[i]))
            {
                cout << S.top();
                S.pop();
            }
            S.push(notation[i]);
        }
    }
    // 스택에 남아있는 연산자 출력
    while (!S.empty())
    {
        cout << S.top();
        S.pop();
    }
}