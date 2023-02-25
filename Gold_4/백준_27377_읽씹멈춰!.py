import sys
input = sys.stdin.readline
for t in range(int(input())):
    n = int(input())
    s, t = map(int, input().split())
    copy_paste_cnt = 0
    write_cnt = 0
    while n//2 >= 0:
        if n & 1:
            write_cnt += 1
            n -= 1
        elif (n//2)*s < t:
            write_cnt += n
            n -= n
            break
        else:
            copy_paste_cnt += 1
            n //= 2
    print(write_cnt*s + copy_paste_cnt*t)
