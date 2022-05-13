#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
//백준 1331번 나이트 투어

int Is_same(char a[][3])		//나이트의 경로의 중복검사를 진행하는 함수
{
	for (int i = 0; i < 35; i++)
		for (int j = i + 1; j < 36; j++)
			if (!strcmp(a[i], a[j]))
				return 1;		//중복이 존재한다면 1을 반환한다.
	return 0;		//중복이 존재하지 않으면 0을 반환한다.
}

int night_road(char a[][3])		//나이트의 경로가 올바른지 판단하는 함수
{
	int flag = 0;
	for (int i = 0; i < 35; i++)
	{
		if (abs(a[i][0] - a[i + 1][0]) == 2 && abs(a[i][1] - a[i + 1][1]) == 1)		//좌우로 2칸 이동하고 상하로 1칸 이동한 경우
			continue;
		else if (abs(a[i][0] - a[i + 1][0]) == 1 && abs(a[i][1] - a[i + 1][1]) == 2)		//좌우로 1칸 이동하고 상하로 2칸 이동한 경우
			continue;
		else
		{
			flag = 1;
			break;
		}
	}
	return flag;		//flag의 값이 0이면 올바르고, 1이면 올바르지 않다.
}

int main(void)
{
	char chess[50][3] = { 0 };
	for (int i = 0; i < 36; i++)
		scanf("%s", &chess[i]);

	if (Is_same(chess))		//중복 검사
		puts("Invalid");
	else if (night_road(chess))		//나이트 규칙 검사
		puts("Invalid");
	else if (!((abs(chess[0][0] - chess[35][0]) == 2 && abs(chess[0][1] - chess[35][1]) == 1) || (abs(chess[0][0] - chess[35][0]) == 1 && abs(chess[0][1] - chess[35][1]) == 2)))		//시작점 복귀 검사
		puts("Invalid");
	else
		puts("Valid");
	return 0;
}