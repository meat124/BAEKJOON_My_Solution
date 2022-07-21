L, C = input().split()
L, C = int(L), int(C)
alpha = list(input().split())
alpha.sort()

password = []


def Print():
    print("".join(password))


def Is_right():
    cnt = 0
    collection = ['a', 'e', 'i', 'o', 'u']
    for i in password:
        if i in collection:
            cnt += 1
    if cnt > 0 and L - cnt > 1:
        return True
    return False


def DFS(level, cur):
    if level == L:
        if Is_right():
            Print()
        return
    for i in range(cur + 1, C):
        password.append(alpha[i])
        DFS(level + 1, i)
        password.pop()


for i in range(C - L + 1):
    password.append(alpha[i])
    DFS(1, i)
    password.pop()
