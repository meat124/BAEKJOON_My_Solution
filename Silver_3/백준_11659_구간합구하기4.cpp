#include <iostream>
#include <vector>
std::vector<int> vec;
int N, M;
long long total_sum = 0;

long long Sum(int start, int end)
{
    long long sum = 0;
    int range = end - start + 1;
    if (range <= N / 2)
        for (auto itr = vec.begin() + start; itr != vec.begin() + end + 1; ++itr)
            sum += *itr;
    else
    {
        sum = total_sum;
        for (auto itr = vec.begin(); itr != vec.begin() + start; ++itr)
            sum -= *itr;
        for (auto itr = vec.begin() + end + 1; itr != vec.end(); ++itr)
            sum -= *itr;
    }
    return sum;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N >> M;

    int n;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> n;
        vec.push_back(n);
        total_sum += n;
    }

    std::pair<int, int> range;

    for (size_t k = 0; k < M; k++)
    {
        std::cin >> range.first >> range.second;
        std::cout << Sum(range.first - 1, range.second - 1) << "\n";
    }
}