from collections import deque
import sys
N, M = map(int, sys.stdin.readline().split())
board = []
vis = [[[0]*(1 << 7) for j in range(M)] for i in range(N)]
dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]


class state():
    x, y, dist, key = 0, 0, 0, 0

    def __init__(self, x, y, dist, key):
        self.x = x
        self.y = y
        self.dist = dist
        self.key = key


def OOB(x, y):
    if x < 0 or x >= N or y < 0 or y >= M:
        return False
    if board[x][y] == '#':
        return False
    return True


def BFS(x, y):
    Q = deque()
    Q.append(state(x, y, 0, 0))
    vis[x][y][0] = True
    while Q:
        cur = Q.popleft()
        if board[cur.x][cur.y] == '1':
            return cur.dist
        for i in range(4):
            nx, ny = cur.x + dx[i], cur.y + dy[i]
            if not OOB(nx, ny):
                continue
            if vis[nx][ny][cur.key]:
                continue
            if board[nx][ny] in "ABCDEF":
                if not (cur.key & (1 << (ord(board[nx][ny]) - ord('A')))):
                    continue
            if board[nx][ny] in "abcdef":
                tmp_key = cur.key | (1 << (ord(board[nx][ny]) - ord('a')))
                vis[nx][ny][tmp_key] = True
                Q.append(state(nx, ny, cur.dist + 1, tmp_key))
                continue
            vis[nx][ny][cur.key] = True
            Q.append(state(nx, ny, cur.dist + 1, cur.key))
    return -1


st_x, st_y = 0, 0
for i in range(N):
    board.append(sys.stdin.readline().rstrip())
    for j in range(M):
        if board[i][j] == '0':
            st_x, st_y = i, j
print(BFS(st_x, st_y))
