#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int T , N , K , W;
int build_time[1005];
int deg[1005];
int DP[1005];
vector<int> adj[1005];
queue<int> Q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> N >> K;
        for (int i = 1;i <= N;i++)
            cin >> build_time[i];
        for (int i = 0;i < K;i++)
        {
            int a , b;
            cin >> a >> b;
            adj[a].push_back(b); // 방향을 반대로 푸시
            deg[b]++;
        }
        cin >> W;

        for (int i = 1;i <= N;i++)
            if (deg[i] == 0)
                Q.push(i);
        copy(build_time , build_time + N + 1 , DP);

        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for (int nxt : adj[cur])
            {
                deg[nxt]--;
                DP[nxt] = max(DP[nxt] , DP[cur] + build_time[nxt]);
                if (deg[nxt] == 0)
                    Q.push(nxt);
            }
        }
        cout << DP[W] << "\n";
        for (int i = 1;i <= N;i++)
            adj[i].clear();
    }
}