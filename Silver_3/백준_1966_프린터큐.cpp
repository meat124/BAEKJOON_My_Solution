#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

std::list<std::pair<int, bool>> que;
std::vector<int> priority;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T; // 테스트 케이스
    std::cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        que.clear();
        priority.clear();
        int N, M; // 문서의 개수, 몇번째로 인쇄 궁금한 문서
        std::cin >> N >> M;
        for (size_t j = 0; j < N; j++)
        {
            int a; // 중요도
            std::cin >> a;
            priority.push_back(a);
            if (j == M)
                que.push_back(std::make_pair(a, true));
            else
                que.push_back(std::make_pair(a, false));
        }
        // 오름차순으로 정렬
        std::sort(priority.begin(), priority.end());
        int cnt = 1;
        while (1)
        {
            if (que.begin()->first != priority.back())
            {
                que.push_back(std::make_pair(que.begin()->first, que.begin()->second));
                que.pop_front();
            }
            else if (que.begin()->first == priority.back()) // 중요도가 가장 높은 문서이면 출력
            {
                if (que.begin()->second == true) // 만약 중요도가 가장 높은 문서 중에서 우리가 몇 번째로 출력하는지 원하는 문서이면
                {
                    que.pop_front();
                    priority.pop_back();
                    std::cout << cnt << "\n";
                    break;
                }
                que.pop_front();
                priority.pop_back();
                cnt++;
            }
        }
    }
}