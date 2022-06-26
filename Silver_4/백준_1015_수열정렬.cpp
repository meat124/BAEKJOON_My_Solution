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
    // stable_sort 가 아닌 그냥 sort 를 해도 되는 이유 > A 의 pair 에서 second 의 값이 크기를 정해주기 때문
    // 따라서 원래부터 first 값만 같았을 뿐, second 값은 다르므로 같은 원소는 존재하지 않는다.
    std::sort(A.begin(), A.end());

    // vector P 의 크기를 미리 할당하지 않으면 vector 참조 오류가 발생한다.
    std::vector<int> P(N);
    for (size_t i = 0; i < N; i++) // O(n)
        P[A[i].second] = i;

    for (auto itr : P)
        std::cout << itr << " ";
}