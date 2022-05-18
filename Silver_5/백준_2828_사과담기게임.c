#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    int left = 1, right = M;
    int j;
    scanf("%d", &j);
    int min_distance = 0; //바구니의 최소 이동거리
    for (int i = 0; i < j; i++)
    {
        int fall;
        scanf("%d", &fall);
        int distance = 0;
        if (left <= fall && fall <= right) //사과가 떨어지는 위치가 바구니 안이라면 움직이지 않는다.
        {
            continue;
        }
        else if (fall < left) //사과가 바구니의 왼쪽에 떨어지는 경우
        {
            distance = left - fall;
            left -= distance;
            right -= distance;
            min_distance += distance;
        }
        else if (right < fall) //사과가 바구니의 오른쪽에 떨어지는 경우
        {
            distance = fall - right;
            right += distance;
            left += distance;
            min_distance += distance;
        }
    }
    printf("%d\n", min_distance);
    return 0;
}