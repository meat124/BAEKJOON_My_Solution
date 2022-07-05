#include <iostream>
#include <math.h>
#include <vector>

std::pair<int, int> departure; // �����
std::pair<int, int> arrival;   // ������

class Planet
{
public:
    std::pair<int, int> center; // �߽� ��ǥ
    int radius;                 // ������
    bool Include_Prince;
    bool Include_arrival;

    Planet() : center(0, 0), radius(0), Include_Prince(false), Include_arrival(false){};
    Planet(int c_x, int c_y, int r)
        : center(c_x, c_y), radius(r)
    {
        // ������� �ȿ� �ִ� ���
        if (std::pow(departure.first - center.first, 2) + std::pow(departure.second - center.second, 2) < std::pow(r, 2))
            Include_Prince = true;
        // ������� �ۿ� �ִ� ���
        else
            Include_Prince = false;

        // �������� �ȿ� �ִ� ���
        if (std::pow(arrival.first - center.first, 2) + std::pow(arrival.second - center.second, 2) < std::pow(r, 2))
            Include_arrival = true;
        // �������� �ۿ� �ִ� ���
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

        int n; // �༺���� ����
        std::cin >> n;

        int cnt = 0; // ��踦 ������ Ƚ��

        for (size_t j = 0; j < n; j++)
        {
            int x, y, r;
            std::cin >> x >> y >> r;
            vec.push_back(Planet(x, y, r));

            // �༺�谡 ������� �������� ��� �ȿ� ������ �ִ� ��� >> ��踦 ������ �ʴ´�.
            // �༺�谡 ������� �������� ��� �ۿ� ������ �ִ� ��� >> ��踦 ������ �ʴ´�.
            // ������� �������� �༺���� �Ȱ� �ۿ� �����ϴ� ��� >> ��踦 ������.
            if (vec[j].Include_arrival != vec[j].Include_Prince)
                cnt++;
        }
        std::cout << cnt << "\n";
    }
}