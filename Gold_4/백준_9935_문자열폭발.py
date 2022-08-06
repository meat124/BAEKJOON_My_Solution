str = input()
bomb = input()
stack = []
for char in str:
    stack.append(char)
    if char == bomb[-1]:
        if "".join(stack[-len(bomb):]) == bomb:
            del stack[-len(bomb):]
result = "".join(stack)

if result == "":
    print("FRULA")
else:
    print(result)
