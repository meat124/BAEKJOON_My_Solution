#include <iostream>
#include <deque>
#include <algorithm>

void FindItr(int n, std::deque<int>::iterator &Iter)
{
    for (size_t i = 0; i < n; i++)
        Iter++;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::deque<int> deq; // 실제 큐 구현

    for (size_t i = 0; i < N; i++)
        deq.push_back(0);

    for (size_t i = 0; i < M; i++)
    {
        int n;
        std::cin >> n;
        deq[n - 1] = i + 1;
    }

    int cnt = 0; // 2번, 3번 연산의 횟수
    for (size_t i = 0; i < M; i++)
    {
        std::deque<int>::iterator itr = std::find(deq.begin(), deq.end(), i + 1);
        int now = itr - deq.begin();
        if (now == 0)
        {
            deq.pop_front();
        }
        else if (now > deq.size() / 2) // 사이즈의 절반보다 크면 back 으로 이동
        {
            int dis = deq.size() - now;
            for (size_t i = 0; i < dis; i++)
            {
                deq.push_front(deq.back());
                deq.pop_back();
                cnt++;
            }
            deq.pop_front();
        }
        else
        {
            int dis = now;
            for (size_t i = 0; i < dis; i++)
            {
                deq.push_back(deq.front());
                deq.pop_front();
                cnt++;
            }
            deq.pop_front();
        }
    }
    std::cout << cnt << "\n";
}