a, b = map(int, input().split())
result = b - a + 1
check = [False]*(b - a + 1)
i = 2
while i**2 <= b:
    sqn = i**2
    j = a//sqn + (0 if a % sqn == 0 else 1)
    while sqn*j <= b:
        if not check[sqn*j - a]:
            check[sqn*j - a] = True
            result -= 1
        j += 1
    i += 1
print(result)
