T = int(input())
for n in range(T):
    str = input()
    total = 0
    tmp = 1
    for i in range(len(str)):
        if str[i] == 'O':
            total += tmp
            tmp += 1
        else:
            tmp = 1
    print(total)
