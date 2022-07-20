str1 = input()
str2 = input()

LCS = [0]*1000

for i in range(len(str1)):
    cnt = 0
    for j in range(len(str2)):
        if cnt < LCS[j]:
            cnt = LCS[j]
        elif str1[i] == str2[j]:
            LCS[j] = cnt + 1
print(max(LCS))
