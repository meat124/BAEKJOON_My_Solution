from collections import deque
import sys
input = sys.stdin.readline
# 26086 어려운 스케줄링, 서강대
N, Q, k = map(int, input().split())
num = deque()
orders = [list(map(int, input().split())) for i in range(Q)]
asc_idx, ord_idx = 0, 0
for i in range(Q - 1, 0, -1):
    if orders[i][0] == 1:
        ord_idx = i
        break


def append_num(st, end):
    # orders[st:end] 에서 숫자를 num에 푸시한다.
    rev = 0
    for i in range(st, end):
        if orders[i][0] == 0:
            if rev & 1:
                num.append(orders[i][1])
            else:
                num.appendleft(orders[i][1])
        elif orders[i][0] == 2:
            rev += 1
    return rev


rev = 0
# 1이 존재하지 않은 경우
if ord_idx == 0:
    if append_num(0, Q) & 1:
        print(num[len(num) - k])
    else:
        print(num[k - 1])

# 1이 존재하는 경우
else:
    append_num(0, ord_idx)
    num = deque(sorted(num))
    if append_num(ord_idx, Q) & 1:
        print(num[len(num) - k])
    else:
        print(num[k - 1])
