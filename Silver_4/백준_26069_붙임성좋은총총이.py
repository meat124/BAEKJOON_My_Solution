import sys
N = int(input())
L = set()
for i in range(N):
    a, b = sys.stdin.readline().rstrip().split()
    if a == "ChongChong" or b == "ChongChong":
        L.update([a, b])
    elif a in L or b in L:
        L.update([a, b])
print(len(L))
