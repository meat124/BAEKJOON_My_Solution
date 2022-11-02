import sys
sys.setrecursionlimit(10**9)  # 재귀 깊이 제한을 늘려준다.
p = [-1]*1000005


def Find(x):
    if(p[x] < 0):
        return x
    p[x] = Find(p[x])
    return p[x]


def Union(u, v):
    u = Find(u)
    v = Find(v)
    if u == v:
        return
    if(p[u] < p[v]):
        p[u] += p[v]
        p[v] = u
    else:
        p[v] += p[u]
        p[u] = v


n, m = map(int, input().split())

for i in range(m):
    order, a, b = map(int, sys.stdin.readline().split())
    # 합집합
    if order == 0:
        if a == b:  # 같은 원소이면 합집합을 수행할 필요 없음
            continue
        # a와b가 서로 다른 원소이면 합친다.
        else:
            Union(a, b)
    # 같은 집합인지 확인
    else:
        if a == b:
            print("YES")
        else:
            if Find(a) == Find(b):  # 부모가 같으면 같은 집합이다.
                print("YES")
            else:  # 부모가 다르면 다른 집합이다.
                print("NO")
