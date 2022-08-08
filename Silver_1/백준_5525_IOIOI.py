import sys

N = int(input())
M = int(input())
S = sys.stdin.readline()

P_N = ""
for i in range(N):
    P_N += "IO"
P_N += "I"

cnt = 0
for i in range(M - len(P_N)):
    if P_N == S[i:i + len(P_N)]:
        cnt += 1
print(cnt)
