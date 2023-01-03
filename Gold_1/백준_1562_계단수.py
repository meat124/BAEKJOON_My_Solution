N = int(input())
MOD = int(1e9)
# DP[i][j][k] 에서
# i : 계단수의 길이
# j : 가장 뒤에 붙은 수
# k : 현재까지 사용된 수를 비트마스킹으로 저장
DP = [[[0]*(1 << 10) for i in range(10)] for i in range(N + 1)]

# 0 으로 시작하는 수는 존재 불가하므로 range(1,10) 으로 설정한다.
for i in range(1, 10):
    DP[1][i][1 << i] = 1

for i in range(2, N + 1):
    for j in range(10):
        for k in range(1 << 10):
            if j > 0:
                DP[i][j][k | (1 << j)] = (
                    DP[i][j][k | (1 << j)] + DP[i - 1][j - 1][k]) % MOD
            if j < 9:
                DP[i][j][k | (1 << j)] = (
                    DP[i][j][k | (1 << j)] + DP[i - 1][j + 1][k]) % MOD
print(sum(DP[N][i][(1 << 10) - 1] for i in range(10)) % MOD)
