#include<iostream>
using namespace std;
int N;
int arr[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    int n;
    for (int i = 0;i < N;i++)
    {
        cin >> n;
        arr[n] += 1;
    }
    for (int i = 1;i <= 10000;i++)
        for (int j = 0;j < arr[i];j++)
            cout << i << "\n";
}