#include <iostream>
#include <string>
#include <set>

int main()
{
    std::string str;
    std::cin >> str;
    std::set<std::string> set;
    for (size_t i = 0; i < str.size(); i++)
    {
        set.insert(str.substr(i));
    }
    for (auto itr : set)
        std::cout << itr << std::endl;
}