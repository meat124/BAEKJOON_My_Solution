import sys


def Is_Word(c):
    if c == ' ':
        return False
    if c >= 'a' and c <= 'z':
        return True
    elif c >= '0' and c <= '9':
        return True
    return False


str = list(sys.stdin.readline().rstrip())
i = 0
result = ""
to_reverse = ""
while i < len(str):
    if str[i] == '<':
        result += str[i]
        while i < len(str) and str[i] != '>':
            i += 1
            result += str[i]
        i += 1
    elif Is_Word(str[i]):
        while i < len(str) and Is_Word(str[i]):
            to_reverse += str[i]
            i += 1
        result += "".join(reversed(to_reverse))
        to_reverse = ""
    else:
        result += str[i]
        to_reverse = ""
        i += 1

print(result)
