import sys
from itertools import combinations
input = sys.stdin.readline
n, k = map(int, input().split())
C = []


def Is_Valid(time_table):
    if sum(time_table[i][3] for i in range(len(time_table))) != k:
        return False
    for a, b in combinations(time_table, 2):
        if a[0] == b[0] and (a[1] <= b[1] <= a[2] or b[1] <= a[1] <= b[2]):
            return False
    return True


for i in range(n):
    c = list(map(int, input().split()))
    # 금요일 수업이면 continue
    if c[0] == 5:
        continue
    # 학점 추가
    c.append(c[2] - c[1] + 1)
    C.append(c)
result = 0
for r in range(1, n + 1):
    for time_table in combinations(C, r):
        if Is_Valid(time_table):
            result += 1
print(result)
