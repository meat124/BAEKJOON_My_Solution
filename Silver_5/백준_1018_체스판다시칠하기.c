#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
int Min_Finder(int min, int cnt)
{
    return (min < cnt) ? min : cnt;
}
int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    int min = 100;
    int cntB = 0, cntW = 0;
    char board[51][51];
    for (int i = 0; i < N; i++)
        scanf("%s", &board[i]);

    for (int i = 0; i < N - 7; i++)
    {
        for (int j = 0; j < M - 7; j++)
        {
            cntB = 0;
            cntW = 0;
            for (int a = i; a < i + 8; a++)
            {
                for (int b = j; b < j + 8; b++)
                {
                    if ((a + b) % 2 == 0)       //시작점 기준
                        if (board[a][b] == 'B') //시작점이 W여야하는데 B라면
                            cntW++;
                        else //시작점이 B여야하는데 W인 경우를 계산
                            cntB++;
                    else                        //시작점과 다른 기준
                        if (board[a][b] == 'B') //시작점은 W이고 만약 그 다음이 B라면 셀필요 x
                            cntB++;
                        else
                            cntW++;
                }
            }
            min = Min_Finder(min, cntB); //최소값 판단
            min = Min_Finder(min, cntW);
        }
    }
    printf("%d\n", min);
    return 0;
}