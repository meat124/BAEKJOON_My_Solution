#include <iostream>
int arr[1001];
int main()
{
    int n;
    std::cin >> n;

    arr[1] = 1;
    arr[2] = 3;
    arr[3] = 5;
    // ���� ���̰� 1�� Ÿ���� arr[i - 1] ���� �����´�.
    // ���� ���̰� 2�� Ÿ���� arr[i - 2] ���� �����´�.
    for (size_t i = 4; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 2];
        arr[i] %= 10007;
    }
    std::cout << arr[n];
}