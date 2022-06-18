#include <iostream>
#include <vector>
#include <algorithm>

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> A, B;
    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        A.push_back(n);
    }
    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        B.push_back(n);
    }

    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), cmp);

    int min = 0;
    for (int i = 0; i < N; i++)
        min += A[i] * B[i];

    std::cout << min;
}