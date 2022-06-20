#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<std::string> v;
    for (size_t i = 0; i < N; i++)
    {
        std::string str;
        std::cin >> str;
        v.push_back(str);
    }

    // 이분 탐색을 위한 정렬
    std::sort(v.begin(), v.end());

    std::string s;
    std::vector<std::string> vec;
    int sum = 0;
    for (size_t i = 0; i < M; i++)
    {
        std::cin >> s;
        if (std::binary_search(v.begin(), v.end(), s) == true)
        {
            vec.push_back(s);
            sum++;
        }
    }
    std::sort(vec.begin(), vec.end());
    std::cout << sum << "\n";
    for (const auto &itr : vec)
        std::cout << itr << "\n";
}