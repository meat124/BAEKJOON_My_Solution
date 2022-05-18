#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    int arr[51];
    int max = 1, min = 1000001;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
        max = arr[i] > max ? arr[i] : max;
        min = arr[i] < min ? arr[i] : min;
    }
    printf("%d", max * min);
    return 0;
}