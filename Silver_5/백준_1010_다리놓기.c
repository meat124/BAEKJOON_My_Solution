#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int T;
    scanf("%d", &T);
    int N, M;
    for (int i = 0; i < T; i++)
    {
        scanf("%d %d", &N, &M);
        int num = 1;
        long long result = 1;
        for (int j = N; j > 0; j--)
        {
            result *= M--;
            result /= num++;
        }
        printf("%lld\n", result);
    }
    return 0;
}