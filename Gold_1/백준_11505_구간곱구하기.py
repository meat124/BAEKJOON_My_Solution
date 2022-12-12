import sys
input = sys.stdin.readline
MOD = int(1e9 + 7)


def Init(st, en, n):
    if st == en:
        tree[n] = num[st]
        return tree[n] % MOD
    mid = (st + en) // 2
    tree[n] = (Init(st, mid, 2*n) * Init(mid + 1, en, 2*n + 1)) % MOD
    return tree[n] % MOD


def Update(st, en, n, idx, prev, nxt):
    if st > idx or en < idx:
        return
    tree[n] = (tree[n]*nxt)//prev
    tree[n] %= MOD
    if st != en:
        mid = (st + en) // 2
        Update(st, mid, 2*n, idx, prev, nxt)
        Update(mid + 1, en, 2*n + 1, idx, prev, nxt)
        tree[n] = (tree[2*n] * tree[2*n + 1]) % MOD


def Multiply(st, en, n, l, r):
    if l > en or r < st:
        return 1
    if l <= st and en <= r:
        return tree[n] % MOD
    mid = (st + en) // 2
    return (Multiply(st, mid, 2*n, l, r) * Multiply(mid + 1, en, 2*n + 1, l, r)) % MOD


N, M, K = map(int, input().split())
num = [int(input()) for i in range(N)]
tree = [0]*(4*N)
Init(0, N - 1, 1)
for i in range(M + K):
    a, b, c = map(int, input().split())
    if a == 1:
        prev = num[b - 1]
        num[b - 1] = c
        if prev == 0:
            Init(0, N - 1, 1)
        else:
            Update(0, N - 1, 1, b - 1, prev, c)
    elif a == 2:
        print(Multiply(0, N - 1, 1, b - 1, c - 1))
