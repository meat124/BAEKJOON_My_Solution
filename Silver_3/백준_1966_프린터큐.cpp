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
    int T; // �׽�Ʈ ���̽�
    std::cin >> T;
    for (size_t i = 0; i < T; i++)
    {
        que.clear();
        priority.clear();
        int N, M; // ������ ����, ���°�� �μ� �ñ��� ����
        std::cin >> N >> M;
        for (size_t j = 0; j < N; j++)
        {
            int a; // �߿䵵
            std::cin >> a;
            priority.push_back(a);
            if (j == M)
                que.push_back(std::make_pair(a, true));
            else
                que.push_back(std::make_pair(a, false));
        }
        // ������������ ����
        std::sort(priority.begin(), priority.end());
        int cnt = 1;
        while (1)
        {
            if (que.begin()->first != priority.back())
            {
                que.push_back(std::make_pair(que.begin()->first, que.begin()->second));
                que.pop_front();
            }
            else if (que.begin()->first == priority.back()) // �߿䵵�� ���� ���� �����̸� ���
            {
                if (que.begin()->second == true) // ���� �߿䵵�� ���� ���� ���� �߿��� �츮�� �� ��°�� ����ϴ��� ���ϴ� �����̸�
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