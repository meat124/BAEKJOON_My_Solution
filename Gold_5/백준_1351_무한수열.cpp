#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long ll;
ll N , P , Q;
unordered_map<ll , ll> A;

ll DFS(ll i)
{
    if (i == 0)
        return 1;
    if (A.find(i) != A.end())
        return A[i];
    A[i] = DFS(i / P) + DFS(i / Q);
    return A[i];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> P >> Q;
    // A7 = A(7/2) + A(7/3) = A3 + A2 = A(3/2) + A(3/3) + A(2/2) + A(2/3) = A1 + A1 + A1 + A0
    A[0] = 1;
    DFS(N);
    cout << A[N];
}