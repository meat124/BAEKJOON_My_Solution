#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> dp(N + 1);

    // bottom-up 방식 사용 > 상향 계획법
    dp[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (!(i % 3))                               // 3으로 나누어떨어지면 실행
            dp[i] = std::min(dp[i], dp[i / 3] + 1); // 위에서 dp[i] = dp[i-1] + 1 을 하고 그 값과 3으로 나눈인덱스 위치의 값에 1을 더한 것을 비교
        if (!(i % 2))                               // 2로 나누어떨어지면 실행
            dp[i] = std::min(dp[i], dp[i / 2] + 1); // 현재 횟수에 1을 더해서 총 연산횟수를 비교함
    }
    std::cout << dp[N];
    return 0;
}