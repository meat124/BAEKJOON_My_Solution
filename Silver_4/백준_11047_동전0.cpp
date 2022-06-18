#include <iostream>
#include <vector>

int main()
{
    int N, K;
    std::cin >> N >> K;
    std::vector<int> vec;
    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        vec.push_back(n);
    }
    auto itr = vec.rbegin();
    int total = 0;
    while (K)
    {
        if (K - *itr < 0)
            *itr++;
        else
        {
            K -= *itr;
            total++;
        }
    }
    std::cout << total;
}