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
        if (*itr <= *(itr + 1)) // 만약 레벨이 증가할 때 점수가 감소하는 형태라면 1만 낮게 낮춘다.
        {
            result += *(itr + 1) - (*itr) + 1;
            *(itr + 1) = *itr - 1;
        }
    }
    std::cout << result;
}