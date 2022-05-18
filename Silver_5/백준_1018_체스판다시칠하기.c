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
                    if ((a + b) % 2 == 0)       //������ ����
                        if (board[a][b] == 'B') //�������� W�����ϴµ� B���
                            cntW++;
                        else //�������� B�����ϴµ� W�� ��츦 ���
                            cntB++;
                    else                        //�������� �ٸ� ����
                        if (board[a][b] == 'B') //�������� W�̰� ���� �� ������ B��� ���ʿ� x
                            cntB++;
                        else
                            cntW++;
                }
            }
            min = Min_Finder(min, cntB); //�ּҰ� �Ǵ�
            min = Min_Finder(min, cntW);
        }
    }
    printf("%d\n", min);
    return 0;
}