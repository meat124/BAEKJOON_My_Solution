#include <iostream>
#include <vector>

int arr[1000001] = {
    0,
};

int main()
{
    int N;
    std::cin >> N;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;

    // Á¡È­½Ä : arr[n] = arr[n - 1] + arr[n - 2]

    for (size_t i = 3; i <= N; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        arr[i] %= 15746;
    }
    std::cout << arr[N];
}