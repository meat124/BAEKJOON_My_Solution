import sys
N = int(input())
board = [list(sys.stdin.readline().rstrip()) for i in range(N)]
e, w, s, n = 0, N, 0, N
for i in range(N):
    for j in range(N):
        if board[i][j] == 'G':
            e = max(e, j)
            w = min(w, j)
            s = max(s, i)
            n = min(n, i)
row, col = min(s, N - 1 - n), min(e, N - 1 - w)
if e == w and s == n:
    print(0)
elif e == w:
    print(row)
elif s == n:
    print(col)
else:
    print(row + col)
