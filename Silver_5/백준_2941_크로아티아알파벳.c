#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[101] = {0};
    int i;
    int cnt = 0;
    scanf("%s", str);
    int len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (str[i + 1] == 61)                           //=일 때
            if ((str[i] == 122) && (str[i - 1] == 100)) // dz= 일 때
            {
                str[i + 1] = 1;
                str[i] = 1;
                str[i - 1] = 1;
                cnt++;
            }
            else
            {
                str[i + 1] = 1;
                str[i] = 1;
                cnt++;
            }
        else if (str[i + 1] == 45) //문자가 - 일 때
        {
            str[i + 1] = 1;
            str[i] = 1;
            cnt++;
        }
        else if (str[i + 1] == 106) // j일때 앞의 문자도 봐야함
        {
            if ((str[i] == 108) || (str[i] == 110)) // lj or nj 인 경우
            {
                str[i + 1] = 1;
                str[i] = 1;
                cnt++;
            }
        }
    }
    for (i = 0; i < len; i++)
        if ((97 <= str[i]) && (str[i] <= 122)) //알파벳 소문자의 범위에서 전부 cnt 1 증가
        {
            str[i] = 1;
            cnt++;
        }
    printf("%d", cnt);
    return 0;
}