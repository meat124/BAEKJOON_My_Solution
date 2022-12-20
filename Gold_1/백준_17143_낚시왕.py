import sys
input = sys.stdin.readline
R, C, M = map(int, input().split())
board = [[0]*C for i in range(R)]


def Get_Nxt_Loc(x, y, v, d):
    # 0,1,2,3...R - 1,R - 2...0 주기로 원위치로 돌아오는 것을 반복한다.
    # 방향이 위 또는 아래인 경우
    if d < 3:
        T = 2*R - 2
        if d == 1:
            v += T - x
        else:
            v += x
        v %= T
        if v >= R:
            return [T - v, y, 1]
        return [v, y, 2]
    else:
        T = 2*C - 2
        if d == 3:
            v += y
        else:
            v += T - y
        v %= T
        if v >= C:
            return [x, T - v, 4]
        return [x, v, 3]


def Move():
    # 상어 이동시키는 함수
    global board
    tmp = [[0]*C for i in range(R)]
    for i in range(R):
        for j in range(C):
            if board[i][j]:
                nx, ny, nd = Get_Nxt_Loc(i, j, board[i][j][0], board[i][j][1])
                if tmp[nx][ny]:
                    tmp[nx][ny] = max(
                        tmp[nx][ny], [board[i][j][0], nd, board[i][j][2]], key=lambda x: x[2])
                else:
                    tmp[nx][ny] = [board[i][j][0], nd, board[i][j][2]]
    board = tmp


def Fishing(col):
    # 낚시왕이 낚시하는 함수
    # 상어를 잡으면 잡은 상어의 크기를 리턴하고
    # 상어를 잡지 못하면 0을 리턴한다.
    for i in range(R):
        if board[i][col]:
            size = board[i][col][2]
            board[i][col] = 0
            return size
    return 0


for i in range(M):
    x, y, v, d, z = map(int, input().split())
    board[x - 1][y - 1] = [v, d, z]


result = 0
for i in range(C):
    result += Fishing(i)
    Move()
print(result)
