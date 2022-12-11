import sys
input = sys.stdin.readline


def Max_Area(st, en):
    if st == en:
        return h[st]
    mid = (st + en)//2
    l, r = mid, mid + 1
    height = min(h[l], h[r])
    width = 2
    tmp = width*height
    while True:
        if (h[l] == 0 or l == st) and (h[r] == 0 or r == en):
            break
        elif h[l] == 0 or l == st:
            height = min(height, h[r + 1])
            r += 1
        elif h[r] == 0 or r == en:
            height = min(height, h[l - 1])
            l -= 1
        else:
            if h[l - 1] > h[r + 1]:
                height = min(height, h[l - 1])
                l -= 1
            else:
                height = min(height, h[r + 1])
                r += 1
        width += 1
        tmp = max(tmp, height*width)
    return max(Max_Area(st, mid), Max_Area(mid + 1, en), tmp)


while True:
    n, *h = list(map(int, input().split()))
    if n == 0:
        break
    print(Max_Area(0, n - 1))
