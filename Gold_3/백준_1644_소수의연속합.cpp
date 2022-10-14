#include<bits/stdc++.h>
using namespace std;
int N , result;
vector<bool> sieve(4000005 , true); // 소수면 true, 아니면 false
vector<int> prime;

// 소수를 찾아서 prime 벡터에 저장
void Sieve_Of_Eratosthenes()
{
    for (int i = 2;i <= N;i++)
    {
        int j = 2;
        while (j * i <= N)
        {
            sieve[j * i] = false;
            j++;
        }
    }
    for (int i = 2;i <= N;i++)
        if (sieve[i])
            prime.push_back(i);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    // 연속된 소수의 합 구하기
    // 소수를 먼저 찾음
    // 400만까지의 소수를 찾아서 벡터에 저장
    // 그 벡터에서 투포인터 시행
    // 시간복잡도 : O(Nlg(lgN))
    Sieve_Of_Eratosthenes();
    // 구간합을 계속해서 구하면서 진행
    // 만약 구간합이 N 보다 작다면 en 을 증가
    // 만약 구간합이 N 보다 크다면 st 를 증가
    // 계속 진행해서 prime[i] 이 N 보다 커지면 break;
    if (N == 1)
        result = 0;
    else
    {
        int prime_cnt = prime.size();
        int st = 0 , en = 0;
        int sum = prime[en];
        // test_case 로 41이 들어온 경우
        // 이 경우 41 까지의 소수들이 벡터에 저장된다.
        while (st < prime_cnt || en < prime_cnt)
        {
            if (en == prime_cnt)
            {
                while (sum > N)
                {
                    sum -= prime[st];
                    st++;
                }
                break;
            }
            if (sum < N)
            {
                en++;
                if (en == prime_cnt)
                {
                    while (sum > N)
                    {
                        sum -= prime[st];
                        st++;
                    }
                    break;
                }
                sum += prime[en];
            }
            else if (sum > N)
            {
                sum -= prime[st];
                st++;
            }
            // 만약 sum == N 인 경우, result 를 증가시키고, en 을 1 증가시킨다.
            else if (sum == N)
            {
                result++;
                en++;
                if (en == prime_cnt)
                {
                    while (sum > N)
                    {
                        sum -= prime[st];
                        st++;
                    }
                    break;
                }
                sum += prime[en];
            }
            // 만약 en 이 prime_cnt 에 도달한 경우? >> 더 이상 en 을 증가시키면 안됨
            // 따라서 st 만 증가시키면서 sum 을 감소시켜야 하는데 이 경우 만약 sum 이 N 보다 작아진 경우
            // 더 이상 sum 이 증가할 여지가 없으므로 break 하고 그 result 를 출력한다.
        }
    }
    cout << result;
    return 0;
}