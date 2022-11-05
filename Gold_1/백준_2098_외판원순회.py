import sys

INF = int(1e9)
N = int(input())
adj = [list(map(int, sys.stdin.readline().split())) for i in range(N)]
DP = [[-1]*(1 << 16) for i in range(20)]


def DFS(cur, vis):
    if vis == (1 << N) - 1:
        if adj[cur][0]:
            return adj[cur][0]
        else:
            return INF
    if DP[cur][vis] != -1:
        return DP[cur][vis]
    DP[cur][vis] = INF
    for i in range(N):
        if vis & (1 << i) or adj[cur][i] == 0:
            continue
        ret = DFS(i, vis | (1 << i))
        if ret == INF:
            DP[cur][vis] = min(DP[cur][vis], INF)
        else:
            DP[cur][vis] = min(DP[cur][vis], ret + adj[cur][i])
    return DP[cur][vis]


print(DFS(0, 1))
