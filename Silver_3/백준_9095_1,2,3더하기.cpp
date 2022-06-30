#include <iostream>

int main()
{
    int T, N;

    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        std::cin >> N;
        auto *arr = new int[N + 1];
        arr[0] = 1;
        arr[1] = 2;
        arr[2] = 4;
        for (int i = 3; i < N; i++)
        {
            arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
        }
        std::cout << arr[N - 1] << "\n";
    }
}