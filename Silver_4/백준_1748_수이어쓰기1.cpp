#include <iostream>
#include <math.h>

int Find_Digit(int n)
{
    int cnt = 0;
    while (n != 0)
    {
        n /= 10;
        cnt++;
    }
    return cnt;
}
int Find_New_Digit(int num, int n) // 숫자와, 그 자릿수를 전달받는다.
{
    if (n == 1) // 한자리수이면 그냥 리턴
        return num;
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += (i + 1) * (9 * pow(10, i));
    }
    sum += n * (num - 10 * pow(10, n - 2) + 1);

    return sum;
}

int main()
{
    int N;
    std::cin >> N;
    std::cout << Find_New_Digit(N, Find_Digit(N));
}