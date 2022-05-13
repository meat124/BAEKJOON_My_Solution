#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
//���� 1331�� ����Ʈ ����

int Is_same(char a[][3])		//����Ʈ�� ����� �ߺ��˻縦 �����ϴ� �Լ�
{
	for (int i = 0; i < 35; i++)
		for (int j = i + 1; j < 36; j++)
			if (!strcmp(a[i], a[j]))
				return 1;		//�ߺ��� �����Ѵٸ� 1�� ��ȯ�Ѵ�.
	return 0;		//�ߺ��� �������� ������ 0�� ��ȯ�Ѵ�.
}

int night_road(char a[][3])		//����Ʈ�� ��ΰ� �ùٸ��� �Ǵ��ϴ� �Լ�
{
	int flag = 0;
	for (int i = 0; i < 35; i++)
	{
		if (abs(a[i][0] - a[i + 1][0]) == 2 && abs(a[i][1] - a[i + 1][1]) == 1)		//�¿�� 2ĭ �̵��ϰ� ���Ϸ� 1ĭ �̵��� ���
			continue;
		else if (abs(a[i][0] - a[i + 1][0]) == 1 && abs(a[i][1] - a[i + 1][1]) == 2)		//�¿�� 1ĭ �̵��ϰ� ���Ϸ� 2ĭ �̵��� ���
			continue;
		else
		{
			flag = 1;
			break;
		}
	}
	return flag;		//flag�� ���� 0�̸� �ùٸ���, 1�̸� �ùٸ��� �ʴ�.
}

int main(void)
{
	char chess[50][3] = { 0 };
	for (int i = 0; i < 36; i++)
		scanf("%s", &chess[i]);

	if (Is_same(chess))		//�ߺ� �˻�
		puts("Invalid");
	else if (night_road(chess))		//����Ʈ ��Ģ �˻�
		puts("Invalid");
	else if (!((abs(chess[0][0] - chess[35][0]) == 2 && abs(chess[0][1] - chess[35][1]) == 1) || (abs(chess[0][0] - chess[35][0]) == 1 && abs(chess[0][1] - chess[35][1]) == 2)))		//������ ���� �˻�
		puts("Invalid");
	else
		puts("Valid");
	return 0;
}