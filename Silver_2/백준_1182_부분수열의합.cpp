#include<iostream>
using namespace std;
int N , S;
int arr[21];
int cnt = 0;

void DFS(int start , int sum)
{
    if (sum == S)
        cnt++;
    for (int i = start;i < N;i++)
        DFS(i + 1 , sum + arr[i]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> S;
    for (int i = 0;i < N;i++)
        cin >> arr[i];

    DFS(0 , 0);

    if (S == 0)
        cout << cnt - 1;
    else
        cout << cnt;
}