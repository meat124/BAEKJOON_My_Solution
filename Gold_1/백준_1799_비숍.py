import sys
N = int(input())
def OOB(x, y): return 0 <= x < N and 0 <= y < N


board = list(list(map(int, sys.stdin.readline().split())) for i in range(N))
# 비숍을 놓을 수 있는 최대 개수를 구하여라
# 행을 -(N-1) ~ (N-1) 까지로 설정한다.
backslash = {}
for i in range(-N + 1, N):
    backslash[i] = False


def Expected_Value(diagonal):
    # 현재 슬래시에서부터
    # 앞으로 놓을 수 있을 것이라 예상되는 최대의 비숍 개수를 리턴한다.
    exp_res = 0
    for i in range(diagonal, 2*N - 1):
        for x in range(i + 1):
            y = i - x
            if OOB(x, y) and board[x][y] and (not backslash[y - x]):
                exp_res += 1
                break
    return exp_res


def DFS(diagonal, cnt):
    global result
    if diagonal == 2*N:
        result = max(result, cnt)
        return

    if Expected_Value(diagonal) + cnt <= result:
        return

    for x in range(diagonal + 1):
        y = diagonal - x
        if OOB(x, y) and board[x][y] and (not backslash[y - x]):
            backslash[y - x] = True
            DFS(diagonal + 1, cnt + 1)
            backslash[y - x] = False
    DFS(diagonal + 1, cnt)


result = 0
DFS(0, 0)
print(result)
