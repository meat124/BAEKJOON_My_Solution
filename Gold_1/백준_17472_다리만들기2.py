from collections import deque
import sys
input = sys.stdin.readline
MAX = 105
N, M = map(int, input().split())
board = [list(map(int, input().split())) for i in range(N)]
vis = [[False]*M for i in range(N)]
dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
# adj[a][b] : a섬에서 b섬까지의 거리의 최솟값
adj = [[MAX]*7 for i in range(7)]


# Out of Bound?
def OOB(x, y):
    if x < 0 or y < 0 or x >= N or y >= M:
        return True
    return False


# 각 섬의 번호를 매긴다.
def Numbering(a, b, n):
    Q = deque()
    Q.append([a, b])
    vis[a][b] = True
    board[a][b] = n
    while Q:
        x, y = Q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if OOB(nx, ny) or board[nx][ny] == 0 or vis[nx][ny]:
                continue
            vis[nx][ny] = True
            board[nx][ny] = n
            Q.append([nx, ny])


# n번 섬에서 다른 섬까지의 가능한 다리의 길이의 최솟값을 구한다.
def Get_Min_Len(a, b, n):
    Q = deque()
    Q.append([a, b])
    vis[a][b] = True
    while Q:
        x, y = Q.popleft()
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            if OOB(nx, ny) or vis[nx][ny]:
                continue
            # 바다를 만난다면 그 방향으로 쭉 전진해서 섬을 만나면 그 거리를 리턴한다.
            if board[nx][ny] == 0:
                tx, ty = nx + dx[i], ny + dy[i]
                while not OOB(tx, ty):
                    # 다른 섬을 발견하면 다리의 길이를 측정한다.
                    cur = board[tx][ty]
                    if cur != 0 and cur != n:
                        new_len = abs(tx - nx) + abs(ty - ny)
                        if new_len < 2:
                            break
                        adj[n][cur] = adj[cur][n] = min(
                            adj[cur][n], new_len)
                        break
                    if cur == n:
                        break
                    tx, ty = tx + dx[i], ty + dy[i]
                continue
            vis[nx][ny] = True
            Q.append([nx, ny])


num = 1
for i in range(N):
    for j in range(M):
        if board[i][j] == 1 and not vis[i][j]:
            Numbering(i, j, num)
            num += 1
for i in range(N):
    vis[i] = [False]*M
for i in range(N):
    for j in range(M):
        if board[i][j] and not vis[i][j]:
            Get_Min_Len(i, j, board[i][j])
# a번 섬에서 b번 섬으로의 다리의 최소길이 측정완료
bridge = []
for i in range(7):
    for j in range(7):
        if i >= j:
            continue
        if adj[i][j] != MAX:
            bridge.append([adj[i][j], i, j])
bridge.sort()

p = [-1]*10


def find(x):
    if p[x] < 0:
        return x
    p[x] = find(p[x])
    return p[x]


def union(x, y):
    x, y = find(x), find(y)
    if x == y:
        return False
    if p[x] > p[y]:
        x, y = y, x
    p[x] += p[y]
    p[y] = x
    return True


result = 0
for w, u, v in bridge:
    if not union(u, v):
        continue
    result += w
S = set()
for i in range(1, num):
    tmp = find(i)
    S.add(tmp)

print(result) if result != 0 and len(S) == 1 else print(-1)
