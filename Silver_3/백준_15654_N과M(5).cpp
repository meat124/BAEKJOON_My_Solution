#include <iostream>
#include <vector>
#include <algorithm>

int N, M;
std::vector<int> seq;
std::vector<int> vec;
bool visit[9] = {false};

void Print()
{
    for (auto itr : seq)
        std::cout << itr << " ";
    std::cout << "\n";
}

void Sequence(int level)
{
    if (level == 0)
    {
        Print();
        return;
    }
    for (size_t i = 0; i < N; i++)
    {
        if (!visit[i])
        {
            visit[i] = true;
            seq.push_back(vec[i]);
            Sequence(level - 1);
            visit[i] = false;
            seq.pop_back();
        }
    }
}

int main()
{
    std::cin >> N >> M;

    int n;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> n;
        vec.push_back(n);
    }
    std::sort(vec.begin(), vec.end());

    Sequence(M);
}