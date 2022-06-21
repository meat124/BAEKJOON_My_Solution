#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> min_cost_stack;

template <typename Iter>
void Find_Min_Cost(Iter begin, Iter end, std::vector<int> &cost) // 인자로 전달받은 구간에 대해서 최저값을 찾는다.
{
    if (begin == end)
        return;
    std::vector<int>::iterator itr1 = begin;
    std::vector<int>::iterator itr2 = end;

    int min_cost = *(end - 1);
    int index = itr2 - itr1 - 1; // 처음에는 end 위치로 초기화
    // 최저가를 찾고 그 위치를 스택에 쌓는다.
    for (; itr1 != itr2; ++itr1)
    {
        if (min_cost > *itr1)
        {
            min_cost = *itr1;
            index = itr1 - begin;
        }
    }
    min_cost_stack.push_back(index);
    Find_Min_Cost(begin, begin + index, cost);
}

int main()
{
    int N;
    std::cin >> N;
    std::vector<int> distance_by_cities;
    std::vector<int> cost_of_oil;

    for (int i = 0; i < N - 1; i++)
    {
        int n;
        std::cin >> n;
        distance_by_cities.push_back(n);
    }
    for (int i = 0; i < N; i++)
    {
        int n;
        std::cin >> n;
        cost_of_oil.push_back(n);
    }
    min_cost_stack.push_back(distance_by_cities.size() - 1);
    // 가장 싼 곳의 지점을 확인하고 그 지점까지의 가는 길에서 또 최저값을 확인하고 다시 무한 반복한다.
    // 재귀함수를 활용한다.
    Find_Min_Cost(cost_of_oil.begin(), cost_of_oil.end() - 1, cost_of_oil);
    if (min_cost_stack[0] == min_cost_stack[1])
        min_cost_stack.erase(min_cost_stack.begin());

    int cost_sum = 0;
    for (int i = 0; i < min_cost_stack.size() - 1; i++)
    {
        // 거리 추출
        // min_cost_stack 은 back 부터 앞의 거리가 존재한다.
        int dis = 0;
        int start_index = min_cost_stack[min_cost_stack.size() - i - 1];
        int end_index = min_cost_stack[min_cost_stack.size() - i - 2];
        for (int j = start_index; j < end_index; j++)
        {
            dis += distance_by_cities[j];
        }
        if (end_index == min_cost_stack[0])
            dis += distance_by_cities[distance_by_cities.size() - 1];
        int cost = dis * cost_of_oil[start_index];
        cost_sum += cost;
    }
    std::cout << cost_sum << "\n";
}