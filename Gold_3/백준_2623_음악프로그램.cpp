#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N , M;
vector<int> adj[1005];
vector<int> result;
int deg[1005];
queue<int> Q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    while (M--)
    {
        int n;
        cin >> n;
        int a;
        cin >> a;
        for (int i = 0;i < n - 1;i++)
        {
            int b;
            cin >> b;
            adj[a].push_back(b);
            deg[b]++;
            a = b;
        }
    }
    for (int i = 1;i <= N;i++)
        if (deg[i] == 0)
            Q.push(i);
    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();
        result.push_back(cur);
        for (int nxt : adj[cur])
        {
            deg[nxt]--;
            if (deg[nxt] == 0)
                Q.push(nxt);
        }
    }
    if (result.size() != N)
        cout << 0;
    else
        for (int i : result)
            cout << i << "\n";
}