#include<iostream>
using namespace std;
int N , K;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    int result = 1;
    for (int i = 1;i <= N;i++) result *= i;
    for (int i = 1;i <= K;i++) result /= i;
    for (int i = 1;i <= N - K;i++) result /= i;
    cout << result;
}