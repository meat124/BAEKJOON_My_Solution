N = int(input())
files = []
for i in range(N):
    files.append(input())
result = ""
for i in range(len(files[0])):
    tmp = files[0][i]
    flag = False
    for j in range(N):
        if files[j][i] != tmp:
            result += "?"
            flag = True
            break
    if flag:
        continue
    result += tmp
print(result)
