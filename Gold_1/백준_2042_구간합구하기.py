import sys
input = sys.stdin.readline
N, M, K = map(int, input().split())
num = [int(input().rstrip()) for i in range(N)]
sum_tree = [0]*(4*N)


def Sum_Tree_Init(st, en, n):
    if st == en:
        sum_tree[n] = num[st]
        return sum_tree[n]
    mid = (st + en) // 2
    sum_tree[n] = Sum_Tree_Init(st, mid, 2*n) + \
        Sum_Tree_Init(mid + 1, en, 2*n + 1)
    return sum_tree[n]


def Prefix_Sum(st, en, n, l, r):
    # st,en : 현재 보고있는 인덱스
    # n : 구간 합 트리의 인덱스
    # l,r : 구간 합을 구하고자 하는 범위
    # 만약 구하고자 하는 범위를 벗어나면 0 리턴
    if l > en or r < st:
        return 0
    # 구하고자 하는 범위가 완전히 속하면 구간 합 트리의 값 리턴
    if l <= st and en <= r:
        return sum_tree[n]
    # 벗어난 범위가 있다면 두 부분으로 나누어서 구간 합을 구한다.
    mid = (st + en) // 2
    return Prefix_Sum(st, mid, 2*n, l, r) + Prefix_Sum(mid + 1, en, 2*n + 1, l, r)


def Update_Value(st, en, n, idx, v):
    if idx < st or idx > en:
        return
    sum_tree[n] += v
    if st == en:
        return
    mid = (st + en) // 2
    Update_Value(st, mid, 2*n, idx, v)
    Update_Value(mid + 1, en, 2*n + 1, idx, v)


Sum_Tree_Init(0, N - 1, 1)
for i in range(M + K):
    a, b, c = map(int, input().split())
    if a == 1:
        # b번째 수를 c로 바꾼다.
        tmp = c - num[b - 1]
        num[b - 1] = c
        Update_Value(0, N - 1, 1, b - 1, tmp)
    elif a == 2:
        # b~c 번째 수까지 합을 구해서 출력한다.
        print(Prefix_Sum(0, N - 1, 1, b - 1, c - 1))
