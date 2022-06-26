#include <iostream>
#include <string>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    int sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        std::string str;
        std::vector<char> word;
        std::cin >> str;
        for (size_t j = 0; j < str.size(); j++)
        {
            if (word.empty())
            {
                word.push_back(str[j]);
            }
            else
            {
                if (word.back() == str[j])
                {
                    word.pop_back();
                }
                else
                {
                    word.push_back(str[j]);
                }
            }
        }
        if (word.empty())
            sum++;
        word.clear();
    }
    std::cout << sum;
}