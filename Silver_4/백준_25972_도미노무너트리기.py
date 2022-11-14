from collections import deque
import sys
N = int(input())
dom = deque(sorted([[*map(int, sys.stdin.readline().split())]
            for i in range(N)]))

result = 0
while dom:
    cur = dom.popleft()
    result += 1
    while dom and cur[0] + cur[1] >= dom[0][0]:
        cur = dom.popleft()
print(result)
