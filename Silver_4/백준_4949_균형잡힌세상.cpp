#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<char> vec;
    std::string str;

    while (1)
    {
        std::getline(std::cin, str); // ����Ʈ�� ���๮�ڸ� ������ ���๮�ڸ� ������ str�� ����
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
            else if (str[i] == ')' && !vec.empty()) // ������ ������� �ʰ� ������ ��ȣ ����
            {
                if (vec.back() == '(')
                {
                    vec.pop_back();
                }
                else // ���� �ݴ� ��ȣ�� ���Դµ� ���� ��ȣ�� ���ÿ� ���ٸ� no ����ؾ���
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
                else // ���� �ݴ� ��ȣ�� ���Դµ� ���� ��ȣ�� ���ÿ� ���ٸ� no ����ؾ���
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