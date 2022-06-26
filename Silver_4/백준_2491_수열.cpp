#include <iostream>
#include <vector>

int main()
{
    int N;
    std::cin >> N;

    std::vector<int> seq;
    for (size_t i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        seq.push_back(n);
    }

    int max_len = 0;
    int cnt = 0;
    // 오름차순 개수
    for (size_t i = 0; i < N - 1; i++)
    {
        if (seq[i] > seq[i + 1])
        {
            max_len = max_len > cnt ? max_len : cnt;
            cnt = 0;
        }
        else
            cnt++;
    }
    max_len = max_len > cnt ? max_len : cnt;

    // 내림차순 개수
    cnt = 0;
    for (size_t i = 0; i < N - 1; i++)
    {
        if (seq[i] < seq[i + 1])
        {
            max_len = max_len > cnt ? max_len : cnt;
            cnt = 0;
        }
        else
            cnt++;
    }
    max_len = max_len > cnt ? max_len : cnt;

    std::cout << max_len + 1;
}