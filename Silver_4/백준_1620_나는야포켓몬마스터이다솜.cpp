#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;

    std::unordered_map<int, std::string> un_map_by_int;    // key = int, value = string 인 unordered_map 선언
    std::unordered_map<std::string, int> un_map_by_string; // key = string, value = int 인 unordered_map 선언

    std::string str;
    for (int i = 0; i < N; i++)
    {
        std::cin >> str;
        un_map_by_int.insert(std::pair<int, std::string>(i + 1, str));
        un_map_by_string.insert(std::pair<std::string, int>(str, i + 1));
    }
    for (int i = 0; i < M; i++)
    {
        std::cin >> str;
        if (isdigit(str[0])) // 만약 숫자를 입력받은 경우 key = int 인 map 으로 탐색
        {
            std::cout << un_map_by_int.find(stoi(str))->second << "\n";
        }
        else // 만약 문자를 입력받은 경우 key = string 인 map 으로 탐색
        {
            std::cout << un_map_by_string.find(str)->second << "\n";
        }
    }
}