#include<iostream>
#include<vector>
#include<set>
using namespace std;
int n , k;
int DP[100005]; // DP[i] 는 i 원을 만드는데 사용한 동전의 최소 개수
set<int> coin_init;
vector<int> coin_value;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0;i < n;i++)
    {
        int v;
        cin >> v;
        coin_init.insert(v);
    }
    // 중복 제거된 동전의 가치를 벡터에 푸시한다.
    // 따라서 벡터는 중복이 존재하지 않고, 오름차순 정렬 상태
    for (auto i : coin_init)
    {
        coin_value.push_back(i);
        DP[i] += 1;
    }
    // 가장 가치가 낮은 동전부터 시작
    for (int i = coin_value[0];i <= k;i++)
    {
        // 0 인 경우, 초기값 설정
        if (DP[i] == 0)
            for (auto j : coin_value)
            {
                if (i < j)
                    break;
                if (DP[i - j] == 0)
                    continue;
                DP[i] = DP[i - j] + 1;
            }
        // 다시 coin_value 를 돌면서 실행
        for (auto j : coin_value)
        {
            if (i < j)
                break;
            if (DP[i - j] == 0)
                continue;
            DP[i] = min(DP[i] , DP[i - j] + 1);
        }
    }
    DP[k] == 0 ? cout << "-1" : cout << DP[k];
}