str = input()
croatia_alphabet = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
for i in croatia_alphabet:
    str = str.replace(i, '*')
print(len(str))
