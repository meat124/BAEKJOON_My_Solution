#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> computer_pair; // 컴퓨터 연결 라인
std::vector<bool> visit(101);                   // 인덱스 값의 컴퓨터가 감염되었는지 확인하는 벡터

void Depth_First_Search(int infested_computer) // 감염된 컴퓨터 번호를 인자로 받음
{
    for (size_t i = 0; i < computer_pair.size(); i++)
    {
        if (computer_pair[i].first == infested_computer && !visit[computer_pair[i].second])
        {
            visit[computer_pair[i].second] = true;
            Depth_First_Search(computer_pair[i].second);
        }
        else if (computer_pair[i].second == infested_computer && !visit[computer_pair[i].first])
        {
            visit[computer_pair[i].first] = true;
            Depth_First_Search(computer_pair[i].first);
        }
    }
}

int main()
{
    int computer;
    std::cin >> computer;
    int connect;
    std::cin >> connect;
    for (size_t i = 0; i < connect; i++)
    {
        int a, b;
        std::cin >> a >> b;
        computer_pair.push_back(std::make_pair(a, b));
    }

    // 백트래킹 방법 중 하나인 dfs(깊이우선탐색) 사용
    Depth_First_Search(1);
    int result = 0;
    for (auto itr : visit)
    {
        if (itr == true)
            result++;
    }
    std::cout << result - 1;
}