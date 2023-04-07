import sys
input = sys.stdin.readline
N, K = map(int, input().split())
A, B, C = [], [], []
for i in range(N):
    a, b, c = map(int, input().split())
    A.append(a + b)
    B.append(a + c)
    C.append(b + c)
A.sort(reverse=True)
B.sort(reverse=True)
C.sort(reverse=True)
print(max(sum(A[:K]), sum(B[:K]), sum(C[:K])))
