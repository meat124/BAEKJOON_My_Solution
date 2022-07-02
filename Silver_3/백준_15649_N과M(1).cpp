#include <iostream>
#include <vector>

int arr[9];
bool visit[9];
std::vector<int> vec;
int cnt, N, M;

void Print()
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << "\n";
}

void DFS(int cnt)
{
    if (cnt > M)
    {
        Print();
        return;
    }
    for (size_t i = 1; i <= N; i++)
    {
        if (visit[i])
            continue;
        visit[i] = true;
        vec.push_back(arr[i]);
        DFS(cnt + 1);
        vec.pop_back();
        visit[i] = false;
    }
}

int main()
{
    std::cin >> N >> M;

    for (size_t i = 0; i < N + 1; i++)
    {
        arr[i] = i;
        visit[i] = false;
    }
    DFS(1);
}