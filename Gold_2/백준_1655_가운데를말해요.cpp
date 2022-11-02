#include<bits/stdc++.h>
using namespace std;
int N;
multiset<int> S;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    int n; cin >> n;
    cout << n << "\n";
    S.insert(n);
    auto itr = S.begin(); // S 원소 개수가 홀수이면 중앙을, 짝수이면 중앙에서 왼쪽을 가리킨다.

    for (int i = 0;i < N - 1;i++)
    {
        cin >> n;
        S.insert(n);
        if (S.size() % 2 == 0) // 말한 개수가 짝수인 경우
        {
            if (n < *itr)
                itr--;
            cout << min(*itr , *next(itr)) << "\n";
        }
        else
        {
            if (n >= *itr)
                itr++;
            cout << *itr << "\n";
        }
    }
}