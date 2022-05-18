#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int X;
    scanf("%d", &X);
    int cnt = 0;
    int deno = 64;
    while (1)
    {
        if (X / deno != 0)
        {
            X -= deno;
            cnt++;
            if (X == 0)
                break;
        }
        deno /= 2;
    }
    printf("%d", cnt);
    return 0;
}