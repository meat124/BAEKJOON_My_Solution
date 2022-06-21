#include <iostream>
#include <string>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, M;
    std::cin >> N >> M;

    std::unordered_map<int, std::string> un_map_by_int;    // key = int, value = string �� unordered_map ����
    std::unordered_map<std::string, int> un_map_by_string; // key = string, value = int �� unordered_map ����

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
        if (isdigit(str[0])) // ���� ���ڸ� �Է¹��� ��� key = int �� map ���� Ž��
        {
            std::cout << un_map_by_int.find(stoi(str))->second << "\n";
        }
        else // ���� ���ڸ� �Է¹��� ��� key = string �� map ���� Ž��
        {
            std::cout << un_map_by_string.find(str)->second << "\n";
        }
    }
}