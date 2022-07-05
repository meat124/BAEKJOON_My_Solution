#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

class statistics
{
public:
    long long N;            // 데이터 총 개수
    long long sum;          // 합계
    long long mean;         // 평균
    long long medium;       // 중앙값
    long long mode;         // 최빈값
    long long mode_cnt = 0; // 최빈값이 나타난 개수
    long long range;        // 범위

    std::map<int, int> data;   // 데이터 보관<값, 나온 횟수>
    std::vector<int> data_vec; // 데이터 보관<값> , 오름차순으로 값을 보관한다.
    // 생성자
    statistics() : sum(0), mean(0), medium(0), mode(0), range(0){};

    void Print()
    {
        std::cout << mean << "\n";
        std::cout << medium << "\n";
        std::cout << mode << "\n";
        std::cout << range << "\n";
    }
    void Find_Mean()
    {
        for (auto itr : data)
            sum += itr.first * itr.second;
        if (sum >= 0)
        {
            if (sum % N > N / 2)
                mean = sum / N + 1;
            else
                mean = sum / N;
        }
        else
        {
            sum *= (-1);
            if (sum % N > N / 2)
                mean = sum / N + 1;
            else
                mean = sum / N;
            mean *= (-1);
        }
    }
    void Sort_data_vec()
    {
        std::sort(data_vec.begin(), data_vec.end());
    }
    void Find_Medium()
    {
        medium = data_vec[N / 2];
    }
    void Find_Mode()
    {
        for (auto itr : data)
        {
            if (itr.second > mode_cnt)
            {
                mode_cnt = itr.second;
                mode = itr.first;
            }
        }
    }
    void Find_Range()
    {
        range = data_vec[data_vec.size() - 1] - data_vec[0];
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    statistics Stat;

    std::cin >> Stat.N;

    int a;
    for (size_t i = 0; i < Stat.N; i++)
    {
        std::cin >> a;
        Stat.data_vec.push_back(a);
        if (Stat.data.find(a) != Stat.data.end())
            Stat.data.find(a)->second++;
        else
            Stat.data.insert({a, 1});
    }
    Stat.Sort_data_vec();
    Stat.Find_Mean();
    Stat.Find_Medium();
    Stat.Find_Mode();
    Stat.Find_Range();
    std::vector<int> temp; // 최빈값이 여러개인 경우를 대비해서 최빈값을 모두 저장해 놓는다.
    for (auto itr : Stat.data)
    {
        if (itr.second == Stat.mode_cnt)
            temp.push_back(itr.first);
    }
    if (temp.size() > 1)     // 만약 최빈값이 두 개 이상인 경우
        Stat.mode = temp[1]; // 두 번째로 작은 값으로 초기화 한다.

    Stat.Print();
}