#include<iostream>
#include<queue>
using namespace std;
int N , K;
int DP[200005];

void BFS()
{
    queue<pair<int , int>> Q;
    Q.push({ N,0 });

    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        DP[cur.first] = min(DP[cur.first] , cur.second);
        if (DP[cur.first - 1] > cur.second)
            Q.push({ cur.first - 1, cur.second + 1 });
        if (DP[cur.first + 1] > cur.second)
            Q.push({ cur.first + 1, cur.second + 1 });
        if (cur.first * 2 < 200005 && DP[cur.first * 2] > cur.second)
            Q.push({ cur.first * 2, cur.second });
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    int t = 0;
    if (N >= K)
    {
        cout << N - K;
        return 0;
    }
    fill(DP , DP + 100005 , 0x7FFFFFFF);
    BFS();
    cout << DP[K];
}