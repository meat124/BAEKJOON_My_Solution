from collections import deque
import sys
input = sys.stdin.readline
N = int(input())
result = deque([N])
cnt = False
for i in range(1, N):
    result.appendleft(i) if cnt else result.append(i)
    cnt ^= True
if result[-1] == N - 1:
    result.reverse()
print('YES')
print(*result)
st, en = 1, N
while st < en:
    print(st, en, end=' ')
    st += 1
    en -= 1
if st == en:
    print(st)
