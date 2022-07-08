#include <iostream>
#include <map>
#include <string>

int Find_Cases(std::map<std::string, int> map)
{
    int tmp = 1;
    for (auto itr : map)
    {
        tmp *= (itr.second + 1);
    }
    return tmp;
}

int main()
{
    int T;
    std::cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        std::map<std::string, int> closet;
        int N; // 의상의 개수
        std::cin >> N;
        for (size_t j = 0; j < N; j++)
        {
            std::string name, catergory;
            std::cin >> name >> catergory;
            if (closet.find(catergory) != closet.end())
                closet.find(catergory)->second++;
            else
                closet.insert({catergory, 1});
        }
        std::cout << Find_Cases(closet) - 1 << "\n";
    }
}