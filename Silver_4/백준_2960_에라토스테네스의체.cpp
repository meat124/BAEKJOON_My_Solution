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
        prime[i] = i; // n ��° �ε����� n ���� �ʱ�ȭ�Ѵ�.
    }

    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j <= N; j += i)
        {
            if (prime[j] != 0) // ���� 0�� �ƴϸ�
            {
                prime[j] = 0; // 0���� �����
                cnt++;        // cnt �� �ø���
                if (cnt == K) // ���� cnt �� K �� �������� ��
                {
                    std::cout << j << "\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}