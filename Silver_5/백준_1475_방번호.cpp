#include <iostream>
#include <string>

int main()
{
    std::string N;
    std::cin >> N;

    int arr[10] = {0};

    for (int i = 0; i < N.size(); i++)
    {
        arr[N[i] - '0']++;
    }
    if ((arr[6] + arr[9]) % 2 == 1) // Ȧ����� 2�� ������ 1�� ���Ѵ�.
        arr[6] = arr[9] = ((arr[6] + arr[9]) / 2) + 1;
    else
        arr[6] = arr[9] = (arr[6] + arr[9]) / 2;
    int max = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    std::cout << max;
}