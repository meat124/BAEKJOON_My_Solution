import sys
N, L = map(int, sys.stdin.readline().split())
x = list(map(int, sys.stdin.readline().split()))
w = list(map(int, sys.stdin.readline().split()))
wx = [x[i]*w[i] for i in range(N)]
X = sum(wx) / sum(w)
print(X)
