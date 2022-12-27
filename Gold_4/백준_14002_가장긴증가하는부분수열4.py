import sys
input = sys.stdin.readline
N = int(input())
seq = list(map(int, input().split()))
# DP[i] : seq[i] 까지 LIS 길이
DP = [1]*N
for i in range(1, N):
    for j in range(0, i):
        # seq[i] 가 더 크면
        if seq[i] > seq[j]:
            DP[i] = max(DP[i], DP[j] + 1)
max_len = max(DP)
print(max_len)
# LIS 원소 복원 방법
# DP 는 LIS 의 길이이고, 그 연속된 원소들의 인덱스마다
# DP 의 길이가 1씩 줄어들 것이다.
# 따라서 역으로 순회하면서 DP 길이가 1씩 감소하는 구간마다 원소를 체크한 뒤
# LIS 를 역으로 출력하면 완성된다.
LIS = []
for i in range(N - 1, -1, -1):
    if DP[i] == max_len:
        LIS.append(seq[i])
        max_len -= 1
print(*LIS[::-1])
