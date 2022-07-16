str = []
for T in range(int(input())):
    str.append(input())
set_str = set(str)
str = list(set_str)
str.sort()
str.sort(key=len)
for i in str:
    print(i)
