#include<iostream>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int N , K;
multimap<int , int> jew; // key : 무게, value : 가격
multiset<int> bag;
long long result = 0; // 훔친 보석의 최대 가격


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    // 가방 당 담을 수 있는 무게 이하의 보석들 중에서 가장 가격이 높은 보석을 택한다.
    // O(NlgN)
    while (N--)
    {
        int m , v;
        cin >> m >> v;
        jew.insert({ v,m });
    }
    // 보석의 가격 순으로 오름차순 정렬
    while (K--)
    {
        int c;
        cin >> c;
        bag.insert(c);
    }
    // 가장 비싼 보석부터 가방에 넣어본다.
    // 보석을 넣을 수 있는 가방이 여러가지인 경우
    // 넣을 수 있는 가방 중, 용량이 가장 작은 것을 선택한다.
    // O(NlgK)
    for (auto i = jew.rbegin();i != jew.rend();i++)
    {
        auto itr = bag.lower_bound(i->second);
        if (itr != bag.end())
        {
            result += i->first;
            bag.erase(itr);
        }
    }
    cout << result;
}