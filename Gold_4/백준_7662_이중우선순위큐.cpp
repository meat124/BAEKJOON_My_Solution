#include<iostream>
#include<set>
using namespace std;
int T , k , n;
char c;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        multiset<int> Q;
        cin >> k;
        while (k--)
        {
            cin >> c >> n;
            if (c == 'I')
                Q.insert(n);
            else if (c == 'D' && !Q.empty())
            {
                if (n == 1)
                    Q.erase(Q.find(*Q.rbegin()));
                else if (n == -1)
                    Q.erase(Q.find(*Q.begin()));
            }
        }
        cout << "\n";
        if (Q.empty())
            cout << "EMPTY\n";
        else
            cout << *Q.rbegin() << " " << *Q.begin() << "\n";
    }
}