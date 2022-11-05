from collections import deque
import sys
N = int(input())
adj = [[] for i in range(N + 1)]


def BFS(n):  # n번 회원의 점수를 리턴한다.
    Q = deque()
    Q.append([n, 0])
    cnt = 0
    vis = [False]*(N + 1)
    vis[n] = True

    while Q:
        cur_node, cur_point = Q.popleft()
        cnt = cur_point
        for i in adj[cur_node]:
            if vis[i]:
                continue
            Q.append([i, cur_point + 1])
            vis[i] = True
    return cnt


while True:
    a, b = map(int, sys.stdin.readline().split())
    if a == -1 and b == -1:
        break
    adj[a].append(b)
    adj[b].append(a)
point = [100]*(N + 1)

for i in range(1, N + 1):
    point[i] = BFS(i)
candidate_point = min(point)
print(candidate_point, point.count(candidate_point))
print(*list(filter(lambda e: point[e] == candidate_point, range(1, N + 1))))
