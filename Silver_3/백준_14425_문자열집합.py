N, M = map(int, input().split())
result = 0
S = set()
for i in range(N):
    S.add(input())
for i in range(M):
    if input() in S:
        result += 1
print(result)
