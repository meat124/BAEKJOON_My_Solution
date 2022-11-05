#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int N;
int adj[20][20];
int DP[20][1 << 16]; // 초기값 -1로 초기화

// 메모이제이션과 비트마스킹 사용
// 마을을 방문한 것을 표시하기 위해 비트마스킹을 사용한다.
// 만약 5개 마을 중 1번 마을을 방문했다면 00001,
// 1,3번 마을을 방문했다면 00101 이다.
// 이렇게 표시를 하면 마을을 방문하는 것을 최대 2^16 가지로 탐색 가능하다.
// 마을을 모두 방문한 경우 11111로 표현된다.

int DFS(int cur , int vis)
{
    if (vis == (1 << N) - 1) // 모든 도시에 방문한 경우 다시 0번 도시로 돌아간다.
        return adj[cur][0] ? adj[cur][0] : INF;
    if (DP[cur][vis] != -1) // 이미 계산되었다면 그냥 그 값을 리턴
        return DP[cur][vis];
    // 아직 모두 방문하지 않은 경우
    DP[cur][vis] = INF;
    for (int i = 0;i < N;i++)
    {
        // vis 에서 방문한 마을이거나, i + 1 마을로 이동하는 길이 없다면 continue
        if (vis & (1 << i) || adj[cur][i] == 0)
            continue;
        // 새로운 재귀 DFS 는 vis 와 (1 << i) 를 합친 방문 비트를 인자로 전달한다.
        // DFS 값에 경로의 비용을 합한 비용 중 가장 작은 값을 리턴값으로 초기화한다.
        int ret = DFS(i , vis | (1 << i));
        if (ret == INF)
            DP[cur][vis] = min(DP[cur][vis] , INF);
        else
            DP[cur][vis] = min(DP[cur][vis] , ret + adj[cur][i]);
    }
    return DP[cur][vis];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    for (int i = 0;i < N;i++)
        for (int j = 0;j < N;j++)
            cin >> adj[i][j];
    memset(DP , -1 , sizeof(DP));
    cout << DFS(0 , 1);
    return 0;
}