#include <iostream>
#include <unordered_set>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, N, M;
    std::cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        std::cin >> N;
        // unordered_set 컨테이너를 사용하면 set 컨테이너를 사용할 때보다 런타임이 절반으로 감소한다.
        std::unordered_set<int> note1;
        for (size_t j = 0; j < N; j++)
        {
            int n;
            std::cin >> n;
            note1.insert(n);
        }

        std::cin >> M;
        for (size_t j = 0; j < M; j++)
        {
            int n;
            std::cin >> n;
            if (note1.find(n) != note1.end())
                std::cout << "1\n";
            else
                std::cout << "0\n";
        }
    }
}