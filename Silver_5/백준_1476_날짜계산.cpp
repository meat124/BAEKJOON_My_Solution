#include <iostream>

typedef struct Year
{
    int E, S, M;
} year;

void PrintYear(year &y)
{
    std::cout << "\n"
              << y.E << " " << y.M << " " << y.S;
}

int main()
{
    year y1, y2;
    std::cin >> y1.E >> y1.M >> y1.S;

    y2.E = y2.M = y2.S = 1;

    int cnt = 1;
    while (true)
    {
        if (y1.E == y2.E && y1.M == y2.M && y1.S == y2.S)
            break;
        y2.E++, y2.M++, y2.S++;
        if (y2.E == 16)
            y2.E -= 15;
        if (y2.M == 29)
            y2.M -= 28;
        if (y2.S == 20)
            y2.S -= 19;
        cnt++;
    }
    std::cout << cnt;
}