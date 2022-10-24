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
            deg[b]++; // b 건물을 짓기 위해 필요한 indeg 1증가
        }
        cin >> W;

        for (int i = 1;i <= N;i++)
            if (deg[i] == 0) // 먼저 indeg 가 0인 것들은 바로 건설 가능하므로 큐에 푸시한다.
                Q.push(i);
        copy(build_time , build_time + N + 1 , DP);
        // 큐가 비어있을 때 까지 반복한다.
        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for (int nxt : adj[cur])
            {
                deg[nxt]--; // cur을 건설하면 indeg 가 1감소하는 것
                DP[nxt] = max(DP[nxt] , DP[cur] + build_time[nxt]); // nxt 를 짓기 위해 걸리는 시간 갱신
                if (deg[nxt] == 0) // 만약 nxt 를 위한 indeg 가 모두 사리지면 큐에 푸시
                    Q.push(nxt);
            }
        }
        cout << DP[W] << "\n"; // 최종 목표 건물인 W 번 건물의 DP 값을 출력한다.
        // 다음 TC 를 위해서 간선 초기화
        for (int i = 1;i <= N;i++)
            adj[i].clear();
    }
}