#include <iostream>
#include <vector>

int N;
std::vector<std::pair<long long, long long>> vec(91);

void Find_Pinary_Number(int current_len)
{
    if (current_len == 1)
        return;
    vec[N - current_len + 1] = (std::make_pair(vec[N - current_len].first + vec[N - current_len].second,
                                               vec[N - current_len].first));
    Find_Pinary_Number(current_len - 1);
}

int main()
{
    std::cin >> N;
    vec[0] = (std::make_pair(0, 1));
    Find_Pinary_Number(N);
    std::cout << vec[N - 1].first + vec[N - 1].second;
}