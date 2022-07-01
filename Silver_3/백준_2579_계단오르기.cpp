#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int stairs;
    std::cin >> stairs;
    std::vector<int> stair_points(stairs + 1);
    std::vector<int> stair_points_current(stairs + 1);
    for (size_t i = 0; i < stairs; i++)
    {
        std::cin >> stair_points[i];
    }
    stair_points_current[0] = stair_points[0];
    stair_points_current[1] = stair_points[0] + stair_points[1];
    // ù��° ����� �� ���� �ʿ� �����Ƿ� 0 �� 1 ��� �� max �� �����Ѵ�.
    stair_points_current[2] = std::max(stair_points[0], stair_points[1]) + stair_points[2];
    for (size_t i = 3; i < stairs; i++)
    {
        // �� �� ��� stair_point[i] �� ���ϹǷ� �ᱹ ������ ����� ������ ��� �Ǿ��ִ�.
        stair_points_current[i] = std::max(stair_points_current[i - 2] + stair_points[i],
                                           stair_points_current[i - 3] + stair_points[i - 1] + stair_points[i]);
    }
    std::cout << stair_points_current[stairs - 1];
}