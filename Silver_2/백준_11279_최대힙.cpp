#include<iostream>
#include<map>
using namespace std;
int N;
map<int , int> arr;
int max_value = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            if (arr.empty())
                cout << 0 << "\n";
            else
            {
                max_value = arr.rbegin()->first;
                cout << max_value << "\n";
                if (arr.rbegin()->second == 1)
                    arr.erase(max_value);
                else
                    arr[max_value]--;
            }
        }
        else
        {
            if (arr.find(x) == arr.end())
                arr.insert({ x,1 });
            else
                arr[x]++;
        }
    }
}