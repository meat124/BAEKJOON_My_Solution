while True:
    str = input()
    if str == "0":
        break
    str_r = "".join(reversed(str))
    if str == str_r:
        print("yes")
    else:
        print("no")
