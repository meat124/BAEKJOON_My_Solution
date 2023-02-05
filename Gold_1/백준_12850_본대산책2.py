import sys
MOD = int(1e9+7)


def Multiply(m1, m2):
    # 행렬 m1,m2 의 곱을 리턴한다.
    ret = [[0]*(len(m2[0])) for i in range(len(m1))]

    for i in range(len(m1)):
        for j in range(len(m2[0])):
            for k in range(len(m1[0])):
                ret[i][j] += m1[i][k]*m2[k][j]
                ret[i][j] %= MOD
    return ret


def Pow(m, n):
    if n == 1:
        return m
    tmp = Pow(m, n//2)
    # 거듭제곱 시행
    ret = Multiply(tmp, tmp)
    if n & 1:
        ret = Multiply(ret, m)
    return ret


D = int(input())
# 정보과학관 = 0, 그리고 지그재그로 번호 할당
matrix = [
    [0, 1, 1, 0, 0, 0, 0, 0],
    [1, 0, 1, 1, 0, 0, 0, 0],
    [1, 1, 0, 1, 1, 0, 0, 0],
    [0, 1, 1, 0, 1, 1, 0, 0],
    [0, 0, 1, 1, 0, 1, 1, 0],
    [0, 0, 0, 1, 1, 0, 0, 1],
    [0, 0, 0, 0, 1, 0, 0, 1],
    [0, 0, 0, 0, 0, 1, 1, 0]
]
# 출발을 정보과학관에서 하는 것으로 시작
first = [[1], [0], [0], [0], [0], [0], [0], [0]]

result = Multiply(Pow(matrix, D), first)
print(result[0][0])
