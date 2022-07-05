#include <iostream>
// 배열을 전역변수로 선언하지 않으면 스택 오버플로우가 발생한다.
// 전역변수는 힙 영역에 메모리를 할당하므로 스택에 할당하는 지역변수에 비해 메모리 사용이 자유롭다.
int arr[1001][1001] = {0};

int main()
{
    int N, K;
    std::cin >> N >> K;
    K = N - K < K ? N - K : K;
    // 파스칼의 정리 사용한다.
    // (N / K) = (N - 1 / K - 1) + (N - 1 / K)

    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;

    for (size_t i = 2; i <= N; i++)
    {
        for (size_t j = 0; j <= K; j++)
        {
            if (j == 0)
                arr[i][j] = 1;
            else if (j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % 10007;
        }
    }
    std::cout << arr[N][K];
}