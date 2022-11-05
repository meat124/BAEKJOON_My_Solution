from collections import deque
import heapq
import sys

N = int(input())
M = int(input())
cost = [[] for i in range(1005)]  # python 에서의 그래프의 인접 리스트 구현

for i in range(M):
    u, v, w = map(int, sys.stdin.readline().split())
    cost[u].append([v, w])
st, en = map(int, sys.stdin.readline().split())

INF = 1e9
dist = [INF]*1005
dist[st] = 0  # 시작값은 0
Q = []
# 우선순위 큐(최소힙)
heapq.heappush(Q, [dist[st], st])  # 거리와, 노드번호를 푸시한다.

# dijkstra
while Q:
    cur_dist, cur_node = heapq.heappop(Q)
    # 기존 거리가 더 빠르다면 continue
    if dist[cur_node] < cur_dist:
        continue
    # 인접 리스트 그래프 탐색
    for nxt_node, nxt_dist in cost[cur_node]:
        new_dist = cur_dist + nxt_dist
        # 만약 더 빠른 경로라면 갱신하고 우선순위 큐에 푸시
        if new_dist < dist[nxt_node]:
            dist[nxt_node] = new_dist
            heapq.heappush(Q, [new_dist, nxt_node])
print(dist[en])
