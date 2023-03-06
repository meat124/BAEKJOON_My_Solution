from collections import deque
import sys
input = sys.stdin.readline
N, L = map(int, input().split())
A = list(map(int, input().split()))
cur = 0
cur_A = deque()
result = 0
for i in range(N):
    cur_A.append(A[i])
    cur += A[i]
    if len(cur_A) > L:
        cur -= cur_A.popleft()
    if 129 <= cur <= 138:
        result += 1
print(result)
