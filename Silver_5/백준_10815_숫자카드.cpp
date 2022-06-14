#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시간 복잡도가 log N > Big O 표기법
int BinarySearch(vector<int> &v, int val)
{
    int begin = 0, end = v.end() - v.begin();

    while (begin <= end)
    {
        int ctr = (begin + end) / 2;

        if (v[ctr] == val)
            return 1;
        else if (v[ctr] < val)
        {
            begin = ctr + 1;
        }
        else // v[ctr] > val 인 경우
        {
            end = ctr - 1;
        }
    }
    return 0;
}

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    int num;

    cin >> N;
    vector<int> vec1;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        vec1.push_back(num);
    }
    // 이진 탐색을 위한 오름차순 정렬
    sort(vec1.begin(), vec1.end());
    cin >> M;
    vector<int> vec2, vec3;
    for (int i = 0; i < M; i++)
    {
        cin >> num;
        vec2.push_back(num);

        // find 함수의 3번째 인자를 vec2.begin() 으로 하면 const 타입이 아니므로 컴파일 오류가 발생한다.
        if (BinarySearch(vec1, vec2[0])) // vec1.end() 가 반환되면 해당 원소가 존재하지 않는 것
            vec3.push_back(1);
        else
            vec3.push_back(0);
        vec2.erase(vec2.begin());
    }

    for (int i = 0; i < M; i++)
        cout << vec3[i] << " ";
}