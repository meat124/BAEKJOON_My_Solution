#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<char> vec;
    std::string str;

    while (1)
    {
        std::getline(std::cin, str); // 디폴트로 개행문자를 만나면 개행문자를 버리고 str에 저장
        if (str == ".")
            break;
        if (str.back() == '.')
            str.pop_back();
        int flag = 0;
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '(' || str[i] == '[')
            {
                vec.push_back(str[i]);
            }
            else if (str[i] == ')' && !vec.empty()) // 스택이 비어있지 않고 오른쪽 괄호 등장
            {
                if (vec.back() == '(')
                {
                    vec.pop_back();
                }
                else // 만약 닫는 괄호가 나왔는데 여는 괄호가 스택에 없다면 no 출력해야함
                {
                    flag = 1;
                    break;
                }
            }
            else if (str[i] == ']' && !vec.empty())
            {
                if (vec.back() == '[')
                {
                    vec.pop_back();
                }
                else // 만약 닫는 괄호가 나왔는데 여는 괄호가 스택에 없다면 no 출력해야함
                {
                    flag = 1;
                    break;
                }
            }
            else if (vec.empty() && (str[i] == ')' || str[i] == ']'))
            {
                flag = 1;
                break;
            }
        }
        if (!vec.empty())
        {
            std::cout << "no\n";
        }
        else if (vec.empty() && flag)
        {
            std::cout << "no\n";
        }
        else if (vec.empty())
        {
            std::cout << "yes\n";
        }
        vec.clear();
        str.clear();
    }
}