import sys
N = int(input())
arr = list(map(int, sys.stdin.readline().rstrip().split()))
result = [0]*(N + 1)
S = []

# 스택의 top 보다 크면 pop 하면서 진행, 현재 보고있는 것 보다 큰 탑을 만나면 레이저 수신 가능
for i in range(N):
    while S and S[-1][0] < arr[i]:
        S.pop()
    if S and S[-1][0] >= arr[i]:
        result[i] = S[-1][1] + 1
    S.append([arr[i], i])
result.pop()
print(*result)
