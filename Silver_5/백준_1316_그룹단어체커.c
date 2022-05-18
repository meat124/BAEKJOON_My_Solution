#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int Checker(char str[], int len);

int main(void)
{
    int i, N, cnt = 0;
    ;
    char str[100];
    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%s", str);
        cnt += Checker(str, strlen(str));
    }
    printf("%d", cnt);
    return 0;
}

int Checker(char s[], int len)
{
    int i, j;
    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len; j++)
            if ((s[i] == s[j]) && ((j - i) > 1) && (s[j - 1] != s[j]))
                return 0;
    }
    return 1;
}