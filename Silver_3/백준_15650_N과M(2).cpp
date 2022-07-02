#include <iostream>
#include <vector>

std::vector<int> seq;
bool visit[9] = {false};
int N, M;

void Print()
{
    for (size_t i = 1; i <= M; i++)
        std::cout << seq[i] << " ";
    std::cout << "\n";
}

// 벡터의 원소가 오름차순인지 확인하는 함수
bool Is_Ascend()
{
    if (M == 1)
        return true;
    for (size_t i = 2; i <= M; i++)
    {
        if (seq[i] <= seq[i - 1])
            return false;
    }
    return true; // 오름차순이면 true 를 리턴
}

void DFS(int n)
{
    if (n > M && Is_Ascend())
    {
        Print();
        return;
    }

    for (size_t i = 1; i <= N; i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        seq.push_back(i);
        DFS(n + 1);
        seq.pop_back();
        visit[i] = false;
    }
}

int main()
{
    std::cin >> N >> M;
    seq.push_back(0);
    DFS(1); // 1부터 시작하는 수열
}