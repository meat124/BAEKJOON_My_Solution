from collections import deque
import sys
input = sys.stdin.readline
N = int(input())
result = deque()
mem = []
for i in range(N):
    order = list(input().split())
    if order[0] == '1':
        result.append(order[1])
        mem.append(order)
    elif order[0] == '2':
        result.appendleft(order[1])
        mem.append(order)
    else:
        if len(mem) == 0:
            continue
        elif mem[-1][0] == '1':
            result.pop()
        elif mem[-1][0] == '2':
            result.popleft()
        mem.pop()
print(''.join(result)) if len(result) else print(0)
