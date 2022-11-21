import sys


N, M, K, X = map(int, sys.stdin.readline().split())
A = [0]
A += map(int, sys.stdin.readline().split())
rate = [X]
# lower_cnt[i] 는 1 ~ i 라운드까지 레이팅이 K 보다 낮은 횟수
lower_cnt = [0]
for i in range(1, N + 1):
    rate.append(rate[i - 1] + A[i])
    lower_cnt.append(lower_cnt[i - 1] if rate[i] >=
                     K else lower_cnt[i - 1] + 1)

for i in range(M):
    l, r = map(int, sys.stdin.readline().split())
    print(lower_cnt[r - 1] - lower_cnt[l - 1])
