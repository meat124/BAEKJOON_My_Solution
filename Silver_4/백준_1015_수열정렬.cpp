#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A;
    for (size_t i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        A.push_back(std::make_pair(n, i));
    }
    // stable_sort �� �ƴ� �׳� sort �� �ص� �Ǵ� ���� > A �� pair ���� second �� ���� ũ�⸦ �����ֱ� ����
    // ���� �������� first ���� ������ ��, second ���� �ٸ��Ƿ� ���� ���Ҵ� �������� �ʴ´�.
    std::sort(A.begin(), A.end());

    // vector P �� ũ�⸦ �̸� �Ҵ����� ������ vector ���� ������ �߻��Ѵ�.
    std::vector<int> P(N);
    for (size_t i = 0; i < N; i++) // O(n)
        P[A[i].second] = i;

    for (auto itr : P)
        std::cout << itr << " ";
}