#include <iostream>

int main()
{
    // 무조건 오른쪽으로 진행한다. 1번 or 4번 이동방식을 사용하여 진행하고 2,3번은 각각 한번씩만 사용한다고 생각한다.
    // 즉 가로 길이에서 2를 빼고 출력한다.
    // 만약 가로 길이가 6보다 작다면 5인 경우 > 4칸, 4인경우

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