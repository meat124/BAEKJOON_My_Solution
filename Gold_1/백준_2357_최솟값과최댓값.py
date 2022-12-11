import sys
input = sys.stdin.readline


def Seg_Tree_Init(st, en, n):
    if st == en:
        tree[n] = [num[st], num[en]]
        return tree[n]
    mid = (st + en) // 2
    l, r = Seg_Tree_Init(st, mid, 2*n), Seg_Tree_Init(mid + 1, en, 2*n + 1)
    tree[n] = [min(l[0], r[0]), max(l[1], r[1])]
    return tree[n]


def Find(st, en, n, l, r):
    if en < l or r < st:
        return [1e10, 0]
    if l <= st and en <= r:
        return tree[n]
    mid = (st + en) // 2
    lf, rf = Find(st, mid, 2*n, l, r), Find(mid + 1, en, 2*n + 1, l, r)
    return [min(lf[0], rf[0]), max(lf[1], rf[1])]


N, M = map(int, input().split())
num = [int(input().rstrip()) for i in range(N)]
# tree[i][0] 은 최솟값, tree[i][1] 은 최댓값
tree = [[0, 0]]*(4*N)
Seg_Tree_Init(0, N - 1, 1)
for i in range(M):
    a, b = map(int, input().split())
    print(*Find(0, N - 1, 1, a - 1, b - 1))
