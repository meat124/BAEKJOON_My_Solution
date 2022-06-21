#include <iostream>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> vec;
    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        vec.push_back(n);
    }

    int sum, cnt = 0;
    for (int i = 0; i < N; i++)
    {
        sum = vec[i];
        if (sum == M)
        {
            cnt++;
            continue;
        }
        for (int j = i + 1; j < N; j++)
        {
            sum += vec[j];
            if (sum == M)
            {
                cnt++;
                break;
            }
            else if (sum > M)
                break;
        }
    }
    std::cout << cnt;
}