#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int static compare(const void *first, const void *second)
{
    if (*(int *)first > *(int *)second) //처음이 크면 1 반환
        return 1;
    else if (*(int *)first < *(int *)second) //처음이 작으면 -1 반환
        return -1;
    else
        return 0; //서로 같으면 0 반환
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