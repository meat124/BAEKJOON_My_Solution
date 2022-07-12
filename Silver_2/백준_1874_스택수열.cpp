#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
int seq[100002];
vector<int> vec;
vector<int> base;
vector<char> print;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> seq[i];
        base.push_back(n + 1 - i);
    }
    vec.resize(n + 1);
    for (int i = 1; i <= n; i++)
    {
        while (!base.empty() && seq[i] >= base.back())
        {
            vec.push_back(base.back());
            print.push_back('+');
            base.pop_back();
        }
        if (vec.back() == seq[i])
        {
            vec.pop_back();
            print.push_back('-');
        }
        else
        {
            cout << "NO\n";
            return 0;
        }
    }
    for (auto itr : print)
        cout << itr << "\n";
}