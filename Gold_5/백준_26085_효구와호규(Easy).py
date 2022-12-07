import sys
input = sys.stdin.readline
dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
N, M = map(int, input().split())
board = [list(map(int, input().split())) for i in range(N)]
if (N*M) % 2:
    print(-1)
    exit(0)
flag = False
cnt = 0
for i in range(N):
    for j in range(M):
        for k in range(4):
            nx, ny = i + dx[k], j + dy[k]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if board[i][j] == board[nx][ny]:
                flag = True
    cnt += board[i].count(1)
if cnt % 2:
    print(-1)
elif flag:
    print(1)
else:
    print(-1)
