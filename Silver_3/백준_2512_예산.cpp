#include <iostream>
#include <vector>
#include <algorithm>
int N;                // 지방의 수
long long max_budget; // 총 예산
int res = 0;          // 결과
std::vector<int> budget_request;

// 상한액을 mid 로 설정하고 budget_request 에서 모든 예산의 지불 가능 금액을 더해서 리턴하는 함수
long long calculate(int mid)
{
    long long sum = 0;
    for (size_t i = 0; i < N; i++)
    {
        if (budget_request[i] > mid) // 만약 요청 예산이 현재 mid 보다 크면 mid 를 더한다.
            sum += mid;
        else // 만약 요청 예산이 현재 mid보다 크지 않으면 요소를 더한다.
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