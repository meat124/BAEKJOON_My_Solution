#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int L;
    scanf("%d", &L);
    int S[50];
    for (int i = 0; i < L; i++)
        scanf("%d", &S[i]);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < L; i++) //���� ���� S�� n�� �ִٸ� ������ ���� ������ ������ 0�� �̹Ƿ� 0�� ����ϰ� �����Ѵ�.
        if (S[i] == n)
        {
            printf("0");
            return 0;
        }
    int a = 0, b = 1000; // n�� ���̿� ���ԵǴ� ���� S�� �� �� ��
    for (int i = 0; i < L; i++)
        if (S[i] > a && S[i] < n)
            a = S[i];
        else if (S[i] < b && S[i] > n)
            b = S[i];
    printf("%d\n", (n - a) * (b - n) - 1);
    return 0;
}