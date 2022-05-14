#include <stdio.h>
#include <stdlib.h>
//���� 1417�� ��ȸ�ǿ� ����
int Other_Vote(int a[], int n) //��ȣ 1���� ������ ������ �ĺ� �� ���� ǥ�� ���� ���� �ĺ��� �ε����� ��ȯ
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
    int fake = 0; //�ż��� ǥ�� ��
    while (1)
    {
        int index = Other_Vote(vote, N);
        if (index == 0) //���� 0�̸� ���� ���� ǥ�� ���� ����� �ڽ��̹Ƿ� �ݺ����� Ż��
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