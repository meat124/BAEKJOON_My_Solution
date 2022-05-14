#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[10000];
    scanf("%s", str);
    int zero = 0, one = 0;

    char *ptr = str;

    while (*ptr != 0)
    {
        if (*ptr == '0')
        {
            zero++;
            while (*ptr == '0')
                ptr++; //포인터를 0이 아닐때까지 민다.
        }
        else if (*ptr == '1')
        {
            one++;
            while (*ptr == '1')
                ptr++; //포인터를 1이 아닐때까지 민다.
        }
    }
    int min = zero < one ? zero : one;
    printf("%d\n", min);
    return 0;
}