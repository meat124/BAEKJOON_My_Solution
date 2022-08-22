#include<iostream>
#include<set>
#include<map>
using namespace std;
int N , Q;
map<int , int> A;
set<int> S; // 명소인 구역 번호를 저장한다.
int cur_state = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> Q;
    for (int i = 0;i < N;i++)
    {
        cin >> A[i];
        if (A[i] == 1)
            S.insert(i);
    }
    while (Q--)
    {
        int order;
        cin >> order;
        if (order == 1)
        {
            int i;
            cin >> i;
            if (A[i - 1] == 0)
            {
                A[i - 1] = 1;
                S.insert(i - 1);
            }
            else
            {
                A[i - 1] = 0;
                S.erase(i - 1);
            }
        }
        else if (order == 2)
        {
            int x;
            cin >> x;
            cur_state += x;
            cur_state %= N;
        }
        else if (order == 3)
        {
            // 만약 명소가 존재하지 않는다면
            if (S.empty())
                cout << -1 << "\n";
            else
            {
                // 만약 명소가 자신보다 크거나 같은 번호에 존재한다면
                if (S.lower_bound(cur_state) != S.end())
                    cout << *S.lower_bound(cur_state) - cur_state << "\n";
                // 만약 명소가 자신보다 작은 번호에 존재한다면
                else
                    cout << N - cur_state + *S.begin() << "\n";
            }
        }
    }
}