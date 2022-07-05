#include <iostream>
#include <math.h>
#include <vector>

std::pair<int, int> departure; // 출발점
std::pair<int, int> arrival;   // 도착점

class Planet
{
public:
    std::pair<int, int> center; // 중심 좌표
    int radius;                 // 반지름
    bool Include_Prince;
    bool Include_arrival;

    Planet() : center(0, 0), radius(0), Include_Prince(false), Include_arrival(false){};
    Planet(int c_x, int c_y, int r)
        : center(c_x, c_y), radius(r)
    {
        // 출발점이 안에 있는 경우
        if (std::pow(departure.first - center.first, 2) + std::pow(departure.second - center.second, 2) < std::pow(r, 2))
            Include_Prince = true;
        // 출발점이 밖에 있는 경우
        else
            Include_Prince = false;

        // 도착점이 안에 있는 경우
        if (std::pow(arrival.first - center.first, 2) + std::pow(arrival.second - center.second, 2) < std::pow(r, 2))
            Include_arrival = true;
        // 도착점이 밖에 있는 경우
        else
            Include_arrival = false;
    }
};

int main()
{
    int T;
    std::cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        std::cin >> departure.first >> departure.second;
        std::cin >> arrival.first >> arrival.second;

        std::vector<Planet> vec;

        int n; // 행성계의 개수
        std::cin >> n;

        int cnt = 0; // 경계를 지나는 횟수

        for (size_t j = 0; j < n; j++)
        {
            int x, y, r;
            std::cin >> x >> y >> r;
            vec.push_back(Planet(x, y, r));

            // 행성계가 출발점과 도착점을 모두 안에 가지고 있는 경우 >> 경계를 지나지 않는다.
            // 행성계가 출발점과 도착점을 모두 밖에 가지고 있는 경우 >> 경계를 지나지 않는다.
            // 출발점과 도착점이 행성계의 안과 밖에 존재하는 경우 >> 경계를 지난다.
            if (vec[j].Include_arrival != vec[j].Include_Prince)
                cnt++;
        }
        std::cout << cnt << "\n";
    }
}