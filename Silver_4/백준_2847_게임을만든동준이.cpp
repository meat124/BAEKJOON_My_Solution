#include <iostream>
#include <vector>
int main()
{
    int N;
    std::cin >> N;

    std::vector<int> score;
    for (size_t i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        score.push_back(n);
    }
    int result = 0;
    for (auto itr = score.rbegin(); itr != score.rend() - 1; ++itr)
    {
        if (*itr <= *(itr + 1)) // ���� ������ ������ �� ������ �����ϴ� ���¶�� 1�� ���� �����.
        {
            result += *(itr + 1) - (*itr) + 1;
            *(itr + 1) = *itr - 1;
        }
    }
    std::cout << result;
}