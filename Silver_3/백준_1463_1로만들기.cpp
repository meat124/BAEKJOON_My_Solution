#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> dp(N + 1);

    // bottom-up ��� ��� > ���� ��ȹ��
    dp[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (!(i % 3))                               // 3���� ����������� ����
            dp[i] = std::min(dp[i], dp[i / 3] + 1); // ������ dp[i] = dp[i-1] + 1 �� �ϰ� �� ���� 3���� �����ε��� ��ġ�� ���� 1�� ���� ���� ��
        if (!(i % 2))                               // 2�� ����������� ����
            dp[i] = std::min(dp[i], dp[i / 2] + 1); // ���� Ƚ���� 1�� ���ؼ� �� ����Ƚ���� ����
    }
    std::cout << dp[N];
    return 0;
}