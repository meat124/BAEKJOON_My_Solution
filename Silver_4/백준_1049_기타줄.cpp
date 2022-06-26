#include <iostream>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> vec; // pair �� �����ϴ� ����, pair ���� �귣�� �� ��Ÿ�� ��Ű�� ����, ���� ������ �Էµȴ�.
    std::pair<int, int> p;
    for (size_t i = 0; i < M; i++)
    {
        std::cin >> p.first >> p.second;
        vec.push_back(p);
    }
    std::pair<int, int> min_pay;
    min_pay.first = vec[0].first;
    min_pay.second = vec[0].second;
    for (size_t i = 1; i < M; i++)
    {
        // ������ ��Ű���� ������ �������� ���� > �귣�� �޶� ����
        min_pay.first = min_pay.first < vec[i].first ? min_pay.first : vec[i].first;
        min_pay.second = min_pay.second < vec[i].second ? min_pay.second : vec[i].second;
    }
    int total_sum = 0;
    if (N <= 6)
    {
        total_sum += min_pay.first < min_pay.second * N ? min_pay.first : min_pay.second * N;
    }
    else
    {
        // ��Ű���� ���� 6�� ���ݺ��� �� ��� > 6�� ������ ��Ű���� �ִ´�.
        if (min_pay.first < min_pay.second * 6)
        {
            total_sum += min_pay.first * (N / 6);
            // ��Ű���� �ְ� ���� �������� ��Ű���� ������ ���ݺ��ؼ� �� �ɷ� �ִ´�.
            if (min_pay.first < min_pay.second * (N % 6))
                total_sum += min_pay.first;
            else
                total_sum += min_pay.second * (N % 6);
        }
        // ��Ű���� ���� 6�� ���ݺ��� ��� ��� > ��Ű���� ��� �� ���� ����
        else
            total_sum += min_pay.second * N;
    }
    std::cout << total_sum;
}