#include<bits/stdc++.h>
using namespace std;
int N;
map<string , int> arr;
set<char> result;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        string str;
        cin >> str;
        arr[str]++;
    }
    for (auto i : arr)
        for (auto j : arr)
        {
            if (i == j)
                if (i.second == 1)
                    continue;
            result.insert(max(i.first[0] , j.first[1]));
        }
    cout << result.size() << "\n";
    for (auto i : result)
        cout << i << " ";
}