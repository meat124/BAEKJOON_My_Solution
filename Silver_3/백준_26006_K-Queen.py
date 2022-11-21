import sys


N, K = map(int, sys.stdin.readline().split())
R, C = map(int, sys.stdin.readline().split())
board = []
# 6시 방향부터 반시계로 회전
dx, dy = [1, 1, 0, -1, -1, -1, 0, 1], [0, 1, 1, 1, 0, -1, -1, -1]

# 현재 공격당하고 있으면 True 리턴


def Cur_State(x, y):
    for qx, qy in board:
        if x == qx or y == qy:
            return True
        elif abs(qx - x)/abs(qy - y) == 1:
            return True
    return False
# 공격에서 벗어날 수 있는 경우 True 리턴


def Can_Run(x, y):
    for i in range(8):
        nx, ny = x + dx[i], y + dy[i]
        if nx <= 0 or nx > N or ny <= 0 or ny > N:
            continue
        if not Cur_State(nx, ny):
            return True
    return False


board = [[*map(int, sys.stdin.readline().split())] for i in range(K)]
if Cur_State(R, C):
    if Can_Run(R, C):
        print("CHECK")
    else:
        print("CHECKMATE")
else:
    if Can_Run(R, C):
        print("NONE")
    else:
        print("STALEMATE")
