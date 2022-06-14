#include <iostream>
#include <string>

int Left(std::string s)
{
    int n = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '(')
            n++;
    return n;
}
int Right(std::string s)
{
    int n = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == ')')
            n++;
    return n;
}
int VPS(std::string s) // 순서대로 올라가면서 '(' 가 나온 수 보다 ')'가 나온 수가 많아지면 1 리턴해서 NO 출력
{
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            cnt++;
        else
            cnt--;
        if (cnt < 0)
            return 1;
    }
    return 0;
}

int IsVPS(std::string s)
{
    if (s[0] != '(' && s[s.size() - 1] != ')')
        return 0;
    else if (Left(s) != Right(s))
        return 0;
    else if (VPS(s))
        return 0;
    else
        return 1;
}

int main()
{
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++)
    {
        std::string s;
        std::cin >> s;

        if (IsVPS(s))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
}