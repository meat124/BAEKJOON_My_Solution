#include <iostream>
#include <string>

int FindMinIndexDiffer(const std::string_view s1, const std::string_view s2)
{
    int len = s2.length() - s1.length(); // 두 문자열의 길이 차이
    int result = 100;
    for (int i = 0; i < len + 1; i++)
    {
        int cnt = 0; // 차이
        for (int j = 0; j < s1.length(); j++)
        {
            if (s1[j] != s2[j + i])
                cnt++;
        }
        result = result > cnt ? cnt : result;
    }
    return result;
}

int main()
{
    std::string A, B;
    std::cin >> A >> B;

    std::cout << FindMinIndexDiffer(A, B);
}