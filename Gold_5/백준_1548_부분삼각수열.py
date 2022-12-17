import sys
input = sys.stdin.readline
N = int(input())
seq = list(map(int, input().split()))
seq.sort()
# N 이 1 or 2 인 경우 그대로 출력
result = N
if N > 2:
    result = -1
    for i in range(N - 2):
        for j in range(N - 1, i + 1, -1):
            if seq[i] + seq[i + 1] > seq[j]:
                result = max(result, j - i + 1)
    if result == -1:
        result = 2
print(result)
