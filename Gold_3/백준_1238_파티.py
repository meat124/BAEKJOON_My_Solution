from queue import PriorityQueue
import sys

N, M, X = map(int, sys.stdin.readline().split())
INF = int(1e9)
adj = [[] for i in range(1005)]
adj_rev = [[] for i in range(1005)]  # 방향 뒤집힌 간선

for i in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    adj[u].append([w, v])
    adj_rev[v].append([w, u])

pq = PriorityQueue()
to_X = [INF]*1005  # X 마을로 가는데 걸리는 시간
to_home = [INF]*1005  # 다시 집으로 가는데 걸리는 시간

# X 마을로 가는 cost 계산
to_X[X] = 0
pq.put([to_X[X], X])
while not pq.empty():
    cur_w, cur_n = pq.get()
    if to_X[cur_n] != cur_w:
        continue
    for nxt_w, nxt_n in adj_rev[cur_n]:
        if to_X[nxt_n] <= to_X[cur_n] + nxt_w:
            continue
        to_X[nxt_n] = to_X[cur_n] + nxt_w
        pq.put([to_X[nxt_n], nxt_n])

# 다시 집으로 가는 cost 계산
to_home[X] = 0
pq.put([to_home[X], X])
while not pq.empty():
    cur_w, cur_n = pq.get()
    if to_home[cur_n] != cur_w:
        continue
    for nxt_w, nxt_n in adj[cur_n]:
        if to_home[nxt_n] <= to_home[cur_n] + nxt_w:
            continue
        to_home[nxt_n] = to_home[cur_n] + nxt_w
        pq.put([to_home[nxt_n], nxt_n])

result = 0
for i in range(1, N + 1):
    result = max(result, to_X[i] + to_home[i])
print(result)
