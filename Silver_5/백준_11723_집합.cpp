#include<iostream>
#include<string>
#include<vector>
using namespace std;
int M;
vector<bool> set(25);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> M;
    string order;
    int x;
    while (M--)
    {
        cin >> order;
        if (order == "add")
        {
            cin >> x;
            set[x] = true;
        }
        else if (order == "remove")
        {
            cin >> x;
            set[x] = false;
        }
        else if (order == "check")
        {
            cin >> x;
            cout << set[x] << "\n";
        }
        else if (order == "toggle")
        {
            cin >> x;
            if (set[x])
                set[x] = false;
            else
                set[x] = true;
        }
        else if (order == "all")
        {
            for (int i = 1;i <= 20;i++)
                set[i] = true;
        }
        else if (order == "empty")
        {
            for (int i = 1;i <= 20;i++)
                set[i] = false;
        }
    }
}