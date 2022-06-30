#include <iostream>

int main()
{
    int T, N;

    std::cin >> T;
    for (int i = 0; i < T; i++)
    {
        std::cin >> N;
        auto *arr = new std::pair<int, int>[N + 1];
        arr[0].first = 1;
        arr[0].second = 0;
        arr[1].first = 0;
        arr[1].second = 1;
        for (int i = 2; i <= N; i++)
        {
            arr[i].first = arr[i - 1].first + arr[i - 2].first;
            arr[i].second = arr[i - 1].second + arr[i - 2].second;
        }
        std::cout << arr[N].first << " " << arr[N].second << "\n";
    }
}