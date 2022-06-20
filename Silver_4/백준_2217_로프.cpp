#include <iostream>
#include <algorithm>
#include <vector>

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
    int max = vec.front() * vec.size();
    for (int i = 0; i < vec.size(); i++)
    {
        if (max < *(vec.begin() + i) * (vec.size() - i))
            max = *(vec.begin() + i) * (vec.size() - i);
    }
    std::cout << max;
}