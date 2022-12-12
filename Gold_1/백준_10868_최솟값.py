import sys
input = sys.stdin.readline


def Seg_Tree_Init(st, en, n):
    if st == en:
        tree[n] = num[st]
        return tree[n]
    mid = (st + en) // 2
    tree[n] = min(Seg_Tree_Init(st, mid, 2*n),
                  Seg_Tree_Init(mid + 1, en, 2*n + 1))
    return tree[n]


def Find_Min(st, en, n, l, r):
    if en < l or st > r:
        return 1e10
    if l <= st and en <= r:
        return tree[n]
    mid = (st + en) // 2
    return min(Find_Min(st, mid, 2*n, l, r), Find_Min(mid + 1, en, 2*n + 1, l, r))


N, M = map(int, input().split())
num = [int(input().rstrip()) for i in range(N)]
tree = [0]*(4*N)
Seg_Tree_Init(0, N - 1, 1)
for i in range(M):
    a, b = map(int, input().split())
    print(Find_Min(0, N - 1, 1, a - 1, b - 1))
