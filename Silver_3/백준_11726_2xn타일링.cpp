#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int *number_of_cases = new int[n + 1];
    number_of_cases[0] = 0;
    number_of_cases[1] = 1;
    number_of_cases[2] = 2;

    for (size_t i = 3; i <= n; i++)
    {
        number_of_cases[i] = number_of_cases[i - 2] + number_of_cases[i - 1];
        number_of_cases[i] %= 10007;
    }
    std::cout << number_of_cases[n];
}