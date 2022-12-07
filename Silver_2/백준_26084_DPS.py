from math import factorial
import sys
input = sys.stdin.readline
S = input().rstrip()
handle = [input().rstrip() for i in range(int(input()))]
result = [0, 0, 0]
for i in range(len(handle)):
    for j in range(3):
        if handle[i][0] in S[j]:
            result[j] += 1
deno = 1
if S[0] == S[1]:
    result[1] -= 1
    deno += 1
if S[1] == S[2]:
    result[2] -= 1
    deno += 1
if S[0] == S[2]:
    result[2] -= 1
    deno += 1
if deno == 4:
    deno = 3
print(result[0]*result[1]*result[2] // factorial(deno))
