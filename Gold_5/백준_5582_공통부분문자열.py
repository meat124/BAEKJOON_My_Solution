import sys
str1 = sys.stdin.readline().rstrip()
str2 = sys.stdin.readline().rstrip()
DP = [[0]*4005 for i in range(4005)]
result = 0

for i in range(len(str1)):
    for j in range(len(str2)):
        if str1[i] == str2[j]:
            DP[i][j] = 1
            if i*j != 0:
                DP[i][j] += DP[i - 1][j - 1]
            result = max(result, DP[i][j])
print(result)
