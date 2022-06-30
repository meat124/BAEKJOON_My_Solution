#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> computer_pair; // ��ǻ�� ���� ����
std::vector<bool> visit(101);                   // �ε��� ���� ��ǻ�Ͱ� �����Ǿ����� Ȯ���ϴ� ����

void Depth_First_Search(int infested_computer) // ������ ��ǻ�� ��ȣ�� ���ڷ� ����
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

    // ��Ʈ��ŷ ��� �� �ϳ��� dfs(���̿켱Ž��) ���
    Depth_First_Search(1);
    int result = 0;
    for (auto itr : visit)
    {
        if (itr == true)
            result++;
    }
    std::cout << result - 1;
}