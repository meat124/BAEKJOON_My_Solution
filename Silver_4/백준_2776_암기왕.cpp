#include <iostream>
#include <unordered_set>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int T, N, M;
    std::cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        std::cin >> N;
        // unordered_set �����̳ʸ� ����ϸ� set �����̳ʸ� ����� ������ ��Ÿ���� �������� �����Ѵ�.
        std::unordered_set<int> note1;
        for (size_t j = 0; j < N; j++)
        {
            int n;
            std::cin >> n;
            note1.insert(n);
        }

        std::cin >> M;
        for (size_t j = 0; j < M; j++)
        {
            int n;
            std::cin >> n;
            if (note1.find(n) != note1.end())
                std::cout << "1\n";
            else
                std::cout << "0\n";
        }
    }
}