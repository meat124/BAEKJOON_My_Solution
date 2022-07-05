#include <iostream>
#include <vector>

int N;
std::vector<std::pair<int, int>> calender;
int res[17] = {
    0,
}; // �ִ� 15�ϱ��� ������ �����Ƿ�, �װź��� �ΰ� ���� 17���� �Ҵ��� ��, 0���� �ʱ�ȭ �Ѵ�.

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
    int deadline;                  // ��� ���� ����
    for (size_t i = N; i > 0; i--) // i �� ��� ���۳�¥�̴�.
    {
        deadline = i + calender[i].first;                                 // ��� ���۳�¥�� ����� �ɸ��� �Ⱓ�� ���Ѵ�.
        if (deadline > N + 1)                                             // ���� ����� ����Ǵ� �Ⱓ�� N + 1 ���� ��ٸ� ����� ������ �� ����.
            res[i] = res[i + 1];                                          // ����� ���� �Ұ����ϹǷ� ��� ������ �� ���� ������ �ʱ�ȭ
        else                                                              // ���� ����� ����Ǵ� �Ⱓ�� N + 1 ���� �۰ų� ���Ƽ� ����� ���� ������ ���
            res[i] = Max(res[i + 1], res[deadline] + calender[i].second); // res[i] ���� �� ���� ���� ���� ���� + ���� �ݾ� �� ū ������ �ʱ�ȭ
    }
    // �̷��� �ؼ� res[1] �� �����ϸ� �ִ������� ���� �� �ִ�.
}

int main()
{
    Input();
    Dp();

    std::cout << res[1];
}