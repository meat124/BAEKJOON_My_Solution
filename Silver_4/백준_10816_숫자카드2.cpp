#include <iostream>
#include <unordered_map>

// 해시를 이용해서 풀었지만 입출력 버퍼를 줄인 코드를 작성하지 않으면 시간초과
// 실제로는 해시보다 이분 탐색을 이용하여 푸는 것이 더 빠르다.
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;
    std::unordered_map<int, int> m_map;

    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        m_map[n]++;
    }

    int M;
    std::cin >> M;

    for (int i = 0; i < M; i++)
    {
        int n;
        std::cin >> n;
        std::cout << m_map[n] << " ";
    }
}