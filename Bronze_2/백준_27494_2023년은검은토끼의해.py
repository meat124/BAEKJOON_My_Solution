import sys
input = sys.stdin.readline
N = int(input())
if N < 2023:
    print(0)
else:
    result = 0
    for a in range(2023, N + 1):
        stack = []
        a = str(a)
        for i in range(len(a)):
            if a[i] == '2' and len(stack) == 0:
                stack.append('2')
            elif a[i] == '2' and len(stack) == 2:
                stack.append('2')
            elif a[i] == '0' and len(stack) == 1:
                stack.append('0')
            elif a[i] == '3' and len(stack) == 3:
                stack.append('3')
        if ''.join(stack) == '2023':
            result += 1
    print(result)
