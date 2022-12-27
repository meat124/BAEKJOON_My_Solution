from bisect import bisect_left
import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))
LIS = [int(1e9 + 5)]
DP = [1]*N
for i in range(N):
    if A[i] > LIS[-1]:
        LIS.append(A[i])
        DP[i] = len(LIS)
    else:
        idx = bisect_left(LIS, A[i])
        LIS[idx] = A[i]
        DP[i] = idx + 1
print(len(LIS))
cur_len = len(LIS)
LIS = []
for i in range(N - 1, -1, -1):
    if cur_len == DP[i]:
        LIS.append(A[i])
        cur_len -= 1
print(*LIS[::-1])
