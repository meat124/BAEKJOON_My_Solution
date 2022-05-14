#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void Fill_4(char *p, int n)
{
    p -= n * sizeof(char);
    for (int i = 0; i < n; i++)
    {
        *p = 'A';
        p++;
    }
}

void Fill_2(char *p, int n)
{
    p -= n * sizeof(char);
    for (int i = 0; i < n - 2; i++)
    {
        *p = 'A';
        p++;
    }
    for (int i = 0; i < 2; i++)
    {
        *p = 'B';
        p++;
    }
}

int main(void)
{
    char *poly;
    poly = calloc(100, sizeof(char));
    scanf("%s", poly);

    char *ptr = poly;
    while (*ptr != 0) //배열의 빈 공간을 가리킬 때 까지 반복
    {
        int cnt = 0;
        while (*ptr == '.')
            ptr++; //.가 그만 나올 때 까지 포인터를 이동
        while (*ptr == 'X')
        {
            ptr++; // X가 그만 나올 때 까지 포인터를 이동
            cnt++; // X의 개수를 센다.
        }
        /*여기까지 오면 X의 개수가 세어진 상태로 현재 포인터는 .을 가리키고 있다.*/
        if (cnt % 2)
        {
            puts("-1");
            return 0;
        }
        else if (cnt % 4 == 0)
        {
            Fill_4(ptr, cnt);
            ptr++;
        }
        else
        {
            Fill_2(ptr, cnt);
            ptr++;
        }
    }
    printf("%s\n", poly);

    return 0;
}