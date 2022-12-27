from bisect import bisect_left
import sys
input = sys.stdin.readline
N = int(input())
seq = list(map(int, input().split()))
MAX = int(1e9 + 5)
LIS = [MAX]
for i in seq:
    if i > LIS[-1]:
        LIS.append(i)
    else:
        idx = bisect_left(LIS, i)
        LIS[idx] = i
print(len(LIS))
