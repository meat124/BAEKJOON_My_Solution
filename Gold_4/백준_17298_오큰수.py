import sys
N = int(input())
A = list(map(int, sys.stdin.readline().rstrip().split()))

S = []
result = [-1]*N

for i in range(len(A)):
    while len(S) != 0 and S[-1][0] < A[i]:
        result[S.pop()[1]] = A[i]
    S.append([A[i], i])
print(*result)
