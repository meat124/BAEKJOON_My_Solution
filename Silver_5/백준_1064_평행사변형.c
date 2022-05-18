#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    double three_point[3][2];
    for (int i = 0; i < 3; i++)
        scanf("%lf %lf", &three_point[i][0], &three_point[i][1]);
    //분모가 0이 되는 부분을 생각했어야 했다.
    if ((three_point[1][0] - three_point[0][0]) * (three_point[2][1] - three_point[1][1]) == (three_point[2][0] - three_point[1][0]) * (three_point[1][1] - three_point[0][1]))
    {
        printf("%lf\n", -1.0);
        return 0;
    }
    double D[3][2]; //순서대로 대각점이 각각 A,B || A,C || B,C인 경우를 초기화 한다.
    // x좌표 초기화
    D[0][0] = (three_point[0][0] + three_point[1][0]) - three_point[2][0];
    D[1][0] = (three_point[0][0] + three_point[2][0]) - three_point[1][0];
    D[2][0] = (three_point[1][0] + three_point[2][0]) - three_point[0][0];
    // y좌표 초기화
    D[0][1] = (three_point[0][1] + three_point[1][1]) - three_point[2][1];
    D[1][1] = (three_point[0][1] + three_point[2][1]) - three_point[1][1];
    D[2][1] = (three_point[1][1] + three_point[2][1]) - three_point[0][1];

    double perimeter[3];
    double AB = sqrt(pow(three_point[1][0] - three_point[0][0], 2) + pow(three_point[1][1] - three_point[0][1], 2));
    double AC = sqrt(pow(three_point[2][0] - three_point[0][0], 2) + pow(three_point[2][1] - three_point[0][1], 2));
    double BC = sqrt(pow(three_point[2][0] - three_point[1][0], 2) + pow(three_point[2][1] - three_point[1][1], 2));
    //대각점이 A B인 경우의 D를 계산하여 둘레 연산
    double AD = sqrt(pow(D[0][0] - three_point[0][0], 2) + pow(D[0][1] - three_point[0][1], 2));
    double BD = sqrt(pow(D[0][0] - three_point[1][0], 2) + pow(D[0][1] - three_point[1][1], 2));
    perimeter[0] = (AC + AD + BC + BD);
    //대각점이 A C인 경우의 D를 계산하여 둘레 연산
    AD = sqrt(pow(D[1][0] - three_point[0][0], 2) + pow(D[1][1] - three_point[0][1], 2));
    double CD = sqrt(pow(D[1][0] - three_point[2][0], 2) + pow(D[1][1] - three_point[2][1], 2));
    perimeter[1] = (AB + AD + BC + CD);
    //대각점이 B C인 경우의 D를 계산하여 둘레 연산
    BD = sqrt(pow(D[2][0] - three_point[1][0], 2) + pow(D[2][1] - three_point[1][1], 2));
    CD = sqrt(pow(D[2][0] - three_point[2][0], 2) + pow(D[2][1] - three_point[2][1], 2));
    perimeter[2] = (AB + BD + AC + CD);
    double min = 9999999999, max = 0;
    for (int i = 0; i < 3; i++)
    {
        min = min > perimeter[i] ? perimeter[i] : min;
        max = max < perimeter[i] ? perimeter[i] : max;
    }
    printf("%.15lf\n", max - min);
    return 0;
}