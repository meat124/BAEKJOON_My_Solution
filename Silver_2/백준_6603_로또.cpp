#include<iostream>
#include<vector>
using namespace std;
int k;
int arr[15];
int result[6];

void Print()
{
    for (int i = 0;i < 6;i++)
        cout << result[i] << " ";
    cout << "\n";
}

void DFS(int level , int start)
{
    if (level == 6)
    {
        Print();
        return;
    }
    for (int i = start;i < k;i++)
    {
        result[level] = arr[i];
        DFS(level + 1 , i + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (true)
    {
        cin >> k;
        if (k == 0)
            break;
        for (int i = 0;i < k;i++)
            cin >> arr[i];
        DFS(0 , 0);
        cout << "\n";
    }
}