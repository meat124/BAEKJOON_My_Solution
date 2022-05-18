#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int static compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second) //ó���� ũ�� 1 ��ȯ
        return 1;
    else if (*(int *)first < *(int *)second) //ó���� ������ -1 ��ȯ
        return -1;
    else
        return 0; //���� ������ 0 ��ȯ
}

int main(void)
{
    int N;
    scanf("%d", &N);
    int *x;
    x = calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &x[i]);

    qsort(x, N, sizeof(int), compare);

    for (int i = 0; i < N; i++)
        printf("%d\n", x[i]);

    return 0;
}