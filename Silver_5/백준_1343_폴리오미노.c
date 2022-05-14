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
    while (*ptr != 0) //�迭�� �� ������ ����ų �� ���� �ݺ�
    {
        int cnt = 0;
        while (*ptr == '.')
            ptr++; //.�� �׸� ���� �� ���� �����͸� �̵�
        while (*ptr == 'X')
        {
            ptr++; // X�� �׸� ���� �� ���� �����͸� �̵�
            cnt++; // X�� ������ ����.
        }
        /*������� ���� X�� ������ ������ ���·� ���� �����ʹ� .�� ����Ű�� �ִ�.*/
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