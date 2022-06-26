#include <iostream>
#include <string>
#include <map>

// 기존에 key 값을 string 으로 받았더니 string 으로 크기 비교를 하는데 어려움
// 따라서 string 이 아닌 long long 타입으로 key 를 받아서 해결
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N;
    std::cin >> N;

    std::map<long long, int> m_map; // key 는 숫자카드에 적힌 정수가 입력되고, value 는 그 개수가 입력된다.
    long long lld;
    for (size_t i = 0; i < N; i++)
    {
        std::cin >> lld;
        // 입력받은 str 이 m_map 에 존재하는지 확인한다.
        std::map<long long, int>::iterator itr = m_map.find(lld);
        // 만약 str 이 m_map 에 존재하지 않으면 itr == m_map.end() 이다.
        if (itr != m_map.end())
            itr->second++;
        else
            m_map.insert(std::pair<long long, int>(lld, 1)); // 존재하지 않는다면 새롭게 pair 추가하고 value = 1로 시작
    }
    // 가장 많이 가지고 있는 정수가 여러 개 라면 그 중 key 가 작은 것을 출력 해야한다.
    int max = 0; // value 와 비교
    long long result = 0;
    for (auto itr = m_map.begin(); itr != m_map.end(); ++itr)
    {
        if (max < itr->second)
        {
            max = itr->second;
            result = itr->first;
        }
    }
    std::cout << result;
}