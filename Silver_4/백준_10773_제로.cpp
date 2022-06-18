#include <iostream>
#include <vector>

int main()
{
    int K;
    std::cin >> K;
    std::vector<int> vec;
    int n;
    for (int i = 0; i < K; i++)
    {
        std::cin >> n;
        if (n == 0)
            vec.pop_back();
        else
            vec.push_back(n);
    }
    int sum = 0;
    for (auto itr = vec.begin(); itr != vec.end(); ++itr)
    {
        sum += *itr;
    }
    std::cout << sum;
}