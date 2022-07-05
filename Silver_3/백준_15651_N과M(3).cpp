#include <iostream>
#include <vector>

std::vector<int> seq; // 수열을 저장하는 벡터
bool visit[8] = {
    false,
};
int N, M;

void Print()
{
    for (auto itr : seq)
        std::cout << itr << " ";
    std::cout << "\n";
}

void DFS(int current)
{
    if (current > M)
    {
        Print();
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visit[current]) // 만약 current 를 방문하지 않았다면 방문으로 표시하고 수를 벡터에 넣는다.
        {
            visit[current] = true;
            seq.push_back(i);
            DFS(current + 1);
        }
        visit[current] = false;
        seq.pop_back();
    }
    return;
}

int main()
{
    // DFS 사용
    std::cin >> N >> M;

    DFS(1);
}