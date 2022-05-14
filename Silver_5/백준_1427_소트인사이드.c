#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define swap(type, x, y) \
    do                   \
    {                    \
        type t = x;      \
        x = y;           \
        y = t;           \
    } while (0);

void bubble(char arr[], int l) //내림차순 정렬
{
    for (int i = l - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[j + 1])
                swap(char, arr[j], arr[j + 1]);
        }
    }
}

int main(void)
{
    char N[20];
    scanf("%s", N);
    int len = strlen(N);

    bubble(N, len);
    printf("%s\n", N);
    return 0;
}