#include <iostream>
#include <vector>

int N;
std::vector<std::pair<int, int>> calender;
int res[17] = {
    0,
}; // 최대 15일까지 일정이 잡히므로, 그거보다 두개 위인 17까지 할당한 뒤, 0으로 초기화 한다.

int Max(int a, int b)
{
    return a > b ? a : b;
}

void Input()
{
    std::cin >> N;
    calender.push_back(std::make_pair(0, 0));
    for (size_t i = 1; i <= N; i++)
    {
        int a, b;
        std::cin >> a >> b;
        calender.push_back(std::make_pair(a, b));
    }
}

void Dp()
{
    int deadline;                  // 상담 마감 기한
    for (size_t i = N; i > 0; i--) // i 는 상담 시작날짜이다.
    {
        deadline = i + calender[i].first;                                 // 상담 시작날짜에 상담이 걸리는 기간을 더한다.
        if (deadline > N + 1)                                             // 만약 상담이 종료되는 기간이 N + 1 보다 길다면 상담을 진행할 수 없다.
            res[i] = res[i + 1];                                          // 상담이 진행 불가능하므로 상담 이익을 그 전의 값으로 초기화
        else                                                              // 만약 상담이 종료되는 기간이 N + 1 보다 작거나 같아서 상담이 진행 가능한 경우
            res[i] = Max(res[i + 1], res[deadline] + calender[i].second); // res[i] 값을 그 전의 값과 마감 기한 + 현재 금액 중 큰 값으로 초기화
    }
    // 이렇게 해서 res[1] 에 도달하면 최대이익을 얻을 수 있다.
}

int main()
{
    Input();
    Dp();

    std::cout << res[1];
}