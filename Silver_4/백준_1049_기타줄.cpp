#include <iostream>
#include <vector>

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> vec; // pair 를 저장하는 벡터, pair 에는 브랜드 별 기타줄 패키지 가격, 낱개 가격이 입력된다.
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
        // 각각의 패키지와 낱개를 최저가로 선정 > 브랜드 달라도 가능
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
        // 패키지가 낱개 6개 가격보다 싼 경우 > 6개 단위로 패키지로 넣는다.
        if (min_pay.first < min_pay.second * 6)
        {
            total_sum += min_pay.first * (N / 6);
            // 패키지로 넣고 남은 나머지는 패키지와 낱개를 가격비교해서 싼 걸로 넣는다.
            if (min_pay.first < min_pay.second * (N % 6))
                total_sum += min_pay.first;
            else
                total_sum += min_pay.second * (N % 6);
        }
        // 패키지가 낱개 6개 가격보다 비싼 경우 > 패키지를 사용 할 이유 없음
        else
            total_sum += min_pay.second * N;
    }
    std::cout << total_sum;
}