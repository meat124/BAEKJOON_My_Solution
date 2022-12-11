import sys
input = sys.stdin.readline


def Max_Area():
    area = 0
    S = []
    for i in range(n):
        l = i
        while S and S[-1][0] >= heights[i]:
            h, l = S.pop()
            tmp = h*(i - l)
            area = max(area, tmp)
        S.append([heights[i], l])
    for h, idx in S:
        area = max(area, (n - idx)*h)
    return area


while True:
    n, *heights = list(map(int, input().split()))
    if n == 0:
        break
    print(Max_Area())
