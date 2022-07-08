#include <iostream>
#include <vector>
#include <algorithm>
int N;                // ������ ��
long long max_budget; // �� ����
int res = 0;          // ���
std::vector<int> budget_request;

// ���Ѿ��� mid �� �����ϰ� budget_request ���� ��� ������ ���� ���� �ݾ��� ���ؼ� �����ϴ� �Լ�
long long calculate(int mid)
{
    long long sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (budget_request[i] > mid) // ���� ��û ������ ���� mid ���� ũ�� mid �� ���Ѵ�.
            sum += mid;
        else // ���� ��û ������ ���� mid���� ũ�� ������ ��Ҹ� ���Ѵ�.
            sum += budget_request[i];
    }
    return sum;
}

void Binary_Search(int start, int end)
{
    int mid = (start + end) / 2;
    long long result = calculate(mid);
    if (start > end)
        return;
    if (result <= max_budget)
    {
        res = mid;
        Binary_Search(mid + 1, end);
    }
    else
        Binary_Search(start, mid - 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        int tmp;
        std::cin >> tmp;
        budget_request.push_back(tmp);
    }
    std::sort(budget_request.begin(), budget_request.end());

    std::cin >> max_budget;

    Binary_Search(1, budget_request.back());

    std::cout << res;
}