import sys
s = sys.stdin.readline().rstrip()


def Is_Palindrome(s):
    if len(s) & 1:
        if s[:len(s)//2] == s[-1:len(s)//2:-1]:
            return True
    else:
        if s[:len(s)//2] == s[-1:len(s)//2 - 1:-1]:
            return True
    return False


DP = [i for i in range(len(s) + 1)]

for i in range(1, len(s) + 1):
    DP[i] = DP[i - 1] + 1
    for j in range(i - 1, -1, -1):
        if Is_Palindrome(s[j:i]):
            DP[i] = min(DP[j] + 1, DP[i])
print(DP[len(s)])
