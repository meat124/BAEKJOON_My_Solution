import sys
G = list(map(int, sys.stdin.readline().split()))
C = list(map(int, sys.stdin.readline().split()))
result = 0


def Solve():
    ret = 0
    for i in range(3):
        m = min(G[i], C[i])
        G[i] -= m
        C[i] -= m
        if G[i] == 0 and i != 2:
            C[i + 1] += C[i]//3
            C[i] %= 3
        elif G[i] == 0 and i == 2:
            C[0] += C[2]//3
            C[2] %= 3
        ret += m
    return ret


for i in range(6):
    result += Solve()
print(result)
