#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
    int L;
    scanf("%d", &L);
    int S[50];
    for (int i = 0; i < L; i++)
        scanf("%d", &S[i]);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < L; i++) //만약 집합 S에 n이 있다면 가능한 좋은 구간은 무조건 0개 이므로 0을 출력하고 종료한다.
        if (S[i] == n)
        {
            printf("0");
            return 0;
        }
    int a = 0, b = 1000; // n이 사이에 포함되는 집합 S의 양 끝 값
    for (int i = 0; i < L; i++)
        if (S[i] > a && S[i] < n)
            a = S[i];
        else if (S[i] < b && S[i] > n)
            b = S[i];
    printf("%d\n", (n - a) * (b - n) - 1);
    return 0;
}