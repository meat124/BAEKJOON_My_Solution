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
        int digit = Find_Digit(seq.back()); // �ڸ���
        int next = 0;
        for (int i = 0; i < digit; i++) // ���� ������ ���ϴ� �ݺ���
            next += pow(std::to_string(seq.back())[i] - 48, P);
        if (std::find(seq.begin(), seq.end(), next) == seq.end()) // std::find �Լ��� C++ 20 ���� ����
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