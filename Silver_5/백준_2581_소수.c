#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int M, N;
    scanf("%d %d", &M, &N);
    int i, j, k = 0, num, min = 10001, total = 0;
    int breakflag = 0;
    num = M;
    for (i = 0; i < (N - M + 1); i++) // M���� N���� ������ ���� ����
    {
        breakflag = 0;
        for (j = 2; j < num; j++) // num�� �Ҽ����� �Ǻ�
        {
            if (num % j == 0) //���� ������ �������ٸ�
            {
                breakflag = 1;
                break;
            }
        }
        if (num == 1)
        {
            num++;
            continue;
        }
        if (breakflag)
        {
            num++;
            continue;
        }
        k++;
        total += num;
        if (num < min)
            min = num;
        num++;
    }
    if (k == 0)
        printf("-1");
    else
    {
        printf("%d\n", total);
        printf("%d\n", min);
    }
    return 0;
}