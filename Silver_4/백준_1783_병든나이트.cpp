#include <iostream>

int main()
{
    // ������ ���������� �����Ѵ�. 1�� or 4�� �̵������ ����Ͽ� �����ϰ� 2,3���� ���� �ѹ����� ����Ѵٰ� �����Ѵ�.
    // �� ���� ���̿��� 2�� ���� ����Ѵ�.
    // ���� ���� ���̰� 6���� �۴ٸ� 5�� ��� > 4ĭ, 4�ΰ��

    int N, M;
    std::cin >> N >> M;

    if (N >= 3)
    {
        if (M < 5)
            std::cout << M;
        else if (M == 5)
            std::cout << "4";
        else
            std::cout << M - 2;
    }
    else if (N == 2)
    {
        if (M <= 2)
            std::cout << "1";
        else if (M <= 9)
            std::cout << 1 + (M - 1) / 2;
        else
            std::cout << "4";
    }
    else
        std::cout << "1";
}