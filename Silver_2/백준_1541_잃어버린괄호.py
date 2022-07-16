no_minus_equation = input().split('-')
sum = 0
for i in no_minus_equation[0].split('+'):
    sum += int(i)
for i in no_minus_equation[1:]:
    for j in i.split('+'):
        sum -= int(j)
print(sum)
