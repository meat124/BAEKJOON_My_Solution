#include <iostream>
int arr[1001];
int main()
{
    int n;
    std::cin >> n;

    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 5;
    // 가로 길이가 1인 타일은 arr[i - 1] 에서 가져온다.
    // 가로 길이가 2인 타일은 arr[i - 2] 에서 가져온다.
    for (size_t i = 4; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 2];
        arr[i] %= 10007;
    }
    std::cout << arr[n];
}