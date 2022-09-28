#include<bits/stdc++.h>
using namespace std;
const int INF = 1e5;
int N , K;
int result = INF , cases;
bool visited[200005];

void BFS()
{
    queue<pair<int , int>> Q;
    Q.push({ N,0 });
    while (!Q.empty())
    {
        auto cur = Q.front();
        Q.pop();
        visited[cur.first] = true;
        if (result < cur.second)
            break;
        if (cur.first == K)
        {
            result = cur.second;
            cases++;
            continue;
        }
        if (cur.first + 1 <= INF && !visited[cur.first + 1])
            Q.push({ cur.first + 1, cur.second + 1 });
        if (cur.first - 1 >= 0 && !visited[cur.first - 1])
            Q.push({ cur.first - 1, cur.second + 1 });
        if (cur.first * 2 <= INF && !visited[cur.first * 2])
            Q.push({ cur.first * 2, cur.second + 1 });
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    BFS();
    cout << result << "\n" << cases;
}