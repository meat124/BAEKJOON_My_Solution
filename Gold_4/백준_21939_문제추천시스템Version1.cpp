#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
int N , M;
multiset<pair<int , int>> p_set; // first : L, second : P
map<int , int> MM; // key : P, value : L
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    while (N--)
    {
        int P , L;
        cin >> P >> L;
        p_set.insert({ L, P });
        MM[P] = L;
    }
    cin >> M;
    while (M--)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int P , L;
            cin >> P >> L;
            p_set.insert({ L, P });
            MM[P] = L;
        }
        else if (s == "recommend")
        {
            int x;
            cin >> x;
            if (x == 1)
                cout << p_set.rbegin()->second << "\n";
            else if (x == -1)
                cout << p_set.begin()->second << "\n";
        }
        else if (s == "solved")
        {
            int P;
            cin >> P;
            p_set.erase({ MM[P] , P });
        }
    }
}