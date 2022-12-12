import sys
input = sys.stdin.readline


def Max_Area():
    area = 0
    # [높이, 인덱스] 를 저장한다.
    S = []
    for i in range(N):
        l = i
        while S and S[-1][0] >= heights[i]:
            h, l = S.pop()
            area = max(area, h*(i - l))
        S.append([heights[i], l])
    for h, idx in S:
        area = max(area, (N - idx)*h)
    return area


N = int(input())
heights = [int(input().rstrip()) for i in range(N)]
print(Max_Area())
