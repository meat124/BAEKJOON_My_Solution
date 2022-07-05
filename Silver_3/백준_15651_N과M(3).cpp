#include <iostream>
#include <vector>

std::vector<int> seq; // ������ �����ϴ� ����
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
        if (!visit[current]) // ���� current �� �湮���� �ʾҴٸ� �湮���� ǥ���ϰ� ���� ���Ϳ� �ִ´�.
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
    // DFS ���
    std::cin >> N >> M;

    DFS(1);
}