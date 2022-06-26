#include <iostream>
#include <string>
#include <map>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;

    std::map<std::string, std::string> password_collection;
    std::string str_address, str_password;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> str_address >> str_password;
        password_collection.insert(std::pair<std::string, std::string>(str_address, str_password));
    }
    std::string str_find;
    for (size_t i = 0; i < M; i++)
    {
        std::cin >> str_find;
        std::cout << password_collection.find(str_find)->second << "\n";
    }
}