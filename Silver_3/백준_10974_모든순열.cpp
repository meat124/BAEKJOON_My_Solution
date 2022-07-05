#include <iostream>
#include <vector>

int N;
std::vector<int> seq;
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
    for (size_t i = 1; i <= N; i++)
    {
        if (!visit[i])
        {
            seq.push_back(i);
            visit[i] = true;
            Sequence(level - 1);
            seq.pop_back();
            visit[i] = false;
        }
    }
}

int main()
{
    std::cin >> N;

    Sequence(N);
}