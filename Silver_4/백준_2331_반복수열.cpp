#include <iostream>
#include <vector>
#include <math.h>
#include <string>

int Find_Digit(int n)
{
    int digit = 0;
    while (1)
    {
        n /= 10;
        if (n == 0)
        {
            digit++;
            break;
        }
        digit++;
    }
    return digit;
}

int main()
{
    int A, P;
    std::cin >> A >> P;

    std::vector<int> seq;
    seq.push_back(A);
    while (1)
    {
        int digit = Find_Digit(seq.back()); // 자릿수
        int next = 0;
        for (int i = 0; i < digit; i++) // 다음 수열을 구하는 반복문
            next += pow(std::to_string(seq.back())[i] - 48, P);
        if (std::find(seq.begin(), seq.end(), next) == seq.end()) // std::find 함수는 C++ 20 부터 가능
            seq.push_back(next);
        else
        {
            int cnt = 0;
            for (int i = 0; i < seq.size(); i++)
            {
                if (seq[i] != next)
                    cnt++;
                else
                    break;
            }
            std::cout << cnt;
            return 0;
        }
    }
}