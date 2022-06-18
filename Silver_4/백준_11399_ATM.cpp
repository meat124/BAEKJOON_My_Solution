#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> vec;

    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        vec.push_back(n);
    }
    std::sort(vec.begin(), vec.end());

    int sum = 0;
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        sum += vec[i]; // 1 3 6 9 13 으로 변화
        result += sum;
    }
    std::cout << result;
}