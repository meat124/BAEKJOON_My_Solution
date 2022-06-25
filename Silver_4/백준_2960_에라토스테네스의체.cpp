#include <iostream>
#include <vector>

int main()
{
    int N, K;
    int cnt = 0;
    std::cin >> N >> K;

    std::vector<int> prime(N + 1);

    for (int i = 2; i <= N; i++)
    {
        prime[i] = i; // n 번째 인덱스에 n 으로 초기화한다.
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            if (prime[j] != 0) // 만약 0이 아니면
            {
                prime[j] = 0; // 0으로 만들고
                cnt++;        // cnt 를 늘린다
                if (cnt == K) // 만약 cnt 가 K 와 같아지면 끝
                {
                    std::cout << j << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}