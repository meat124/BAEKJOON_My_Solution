#include <iostream>
// �迭�� ���������� �������� ������ ���� �����÷ο찡 �߻��Ѵ�.
// ���������� �� ������ �޸𸮸� �Ҵ��ϹǷ� ���ÿ� �Ҵ��ϴ� ���������� ���� �޸� ����� �����Ӵ�.
int arr[1001][1001] = {0};

int main()
{
    int N, K;
    std::cin >> N >> K;
    K = N - K < K ? N - K : K;
    // �Ľ�Į�� ���� ����Ѵ�.
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