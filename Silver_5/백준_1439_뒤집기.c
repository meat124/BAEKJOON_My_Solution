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
                ptr++; //�����͸� 0�� �ƴҶ����� �δ�.
        }
        else if (*ptr == '1')
        {
            one++;
            while (*ptr == '1')
                ptr++; //�����͸� 1�� �ƴҶ����� �δ�.
        }
    }
    int min = zero < one ? zero : one;
    printf("%d\n", min);
    return 0;
}