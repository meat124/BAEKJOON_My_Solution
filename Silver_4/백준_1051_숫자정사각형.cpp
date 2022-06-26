#include <iostream>
#include <string>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::string str;
    std::vector<char> temp;
    std::vector<std::vector<char>> rectangle;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> str;
        for (size_t j = 0; j < M; j++)
        {
            temp.push_back(str[j]);
        }
        rectangle.push_back(temp);
        temp.clear();
    }

    int area = 0;
    for (size_t k = 0; k < M; k++)
    {
        for (size_t i = 0; i < N - 1; i++)
        {
            for (size_t j = i + 1; j < N; j++)
            {
                if (rectangle[i][k] == rectangle[j][k])
                {
                    int num = rectangle[i][k]; // 그 칸의 값
                    int len = j - i;           // 한 변의 길이
                    if (k + len < M && rectangle[i][k + len] == num && rectangle[j][k + len] == num)
                        area = area < (len + 1) * (len + 1) ? (len + 1) * (len + 1) : area;
                }
            }
        }
    }
    if (area == 0)
        std::cout << "1";
    else
        std::cout << area;
}