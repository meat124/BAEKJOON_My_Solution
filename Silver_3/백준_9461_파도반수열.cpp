#include <iostream>

int main()
{
    int T, N;
    std::cin >> T;
    long long arr[102];
    arr[1] = arr[2] = arr[3] = 1;
    arr[4] = arr[5] = 2;
    for (size_t i = 0; i < T; i++)
    {
        std::cin >> N;
        for (size_t i = 6; i <= N; i++)
        {
            arr[i] = arr[i - 1] + arr[i - 5];
        }
        std::cout << arr[N] << "\n";
    }
}