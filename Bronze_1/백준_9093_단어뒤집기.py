for T in range(int(input())):
    str = list(input().split())
    for i in str:
        print(i[::-1], end=" ")
