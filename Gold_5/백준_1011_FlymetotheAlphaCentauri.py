from math import sqrt
import sys


T = int(input())
for i in range(T):
    x, y = map(int, sys.stdin.readline().split())
    # x,y 사이 거리로 계산
    dis = y - x
    # 시작과 끝은 항상 1광년을 이동한다.
    mid = int(sqrt(dis))
    if dis == mid**2:
        print(2*mid - 1)
    elif dis > mid**2 and dis <= mid**2 + mid:
        print(2*mid)
    else:
        print(2*mid + 1)
