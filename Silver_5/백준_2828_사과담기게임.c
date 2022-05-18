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
    int min_distance = 0; //�ٱ����� �ּ� �̵��Ÿ�
    for (int i = 0; i < j; i++)
    {
        int fall;
        scanf("%d", &fall);
        int distance = 0;
        if (left <= fall && fall <= right) //����� �������� ��ġ�� �ٱ��� ���̶�� �������� �ʴ´�.
        {
            continue;
        }
        else if (fall < left) //����� �ٱ����� ���ʿ� �������� ���
        {
            distance = left - fall;
            left -= distance;
            right -= distance;
            min_distance += distance;
        }
        else if (right < fall) //����� �ٱ����� �����ʿ� �������� ���
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