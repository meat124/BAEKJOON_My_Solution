#include <iostream>
#include <vector>

struct Airline
{
    int city1;
    int city2;
};

int main()
{
    int T; // test case
    std::cin >> T;

    int N, M; // nations ,airline
    for (size_t i = 0; i < T; i++)
    {
        std::vector<Airline> air;
        std::cin >> N >> M;
        for (size_t j = 0; j < M; j++)
        {
            int c1, c2;
            std::cin >> c1 >> c2;
            Airline c;
            c.city1 = c1;
            c.city2 = c2;
            air.push_back(c);
        }
        std::cout << N - 1 << "\n";
    }
}