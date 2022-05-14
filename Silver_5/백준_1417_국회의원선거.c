#include <stdio.h>
#include <stdlib.h>
//백준 1417번 국회의원 선거
int Other_Vote(int a[], int n) //기호 1번을 제외한 나머지 후보 중 가장 표를 많이 받은 후보의 인덱스를 반환
{
    int max = 0;
    for (int i = 1; i < n; i++)
        max = a[max] > a[i] ? max : i;
    return max;
}

int main()
{
    int N;
    scanf("%d", &N);

    if (N == 1)
    {
        puts("0");
        return 0;
    }
    int *vote;
    vote = calloc(N, sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &vote[i]);
    int fake = 0; //매수할 표의 수
    while (1)
    {
        int index = Other_Vote(vote, N);
        if (index == 0) //만약 0이면 가장 많은 표를 받은 사람이 자신이므로 반복문을 탈출
            break;
        else
        {
            vote[index]--;
            vote[0]++;
            fake++;
        }
    }
    printf("%d\n", fake);
    return 0;
}