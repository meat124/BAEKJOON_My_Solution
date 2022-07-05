#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::string str;
    std::cin >> str;

    std::vector<char> vec;
    int cnt = 0;
    for (size_t i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            vec.push_back('(');
        else if (str[i] == ')')
        {
            if (str[i - 1] == '(') // ·¹ÀÌÀú on
            {
                cnt += vec.size() - 1;
                vec.pop_back();
            }
            else
            {
                cnt++;
                vec.pop_back();
            }
        }
    }
    std::cout << cnt;
}