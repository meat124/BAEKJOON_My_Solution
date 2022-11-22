import sys
N = int(input())
tier = list(sys.stdin.readline().split())
diff = {'B': 0, 'S': 1, 'G': 2, 'P': 3, 'D': 4}


def Comp_Tier(t1, t2):
    if diff[t1[0]] > diff[t2[0]]:
        return 1
    elif diff[t1[0]] < diff[t2[0]]:
        return -1
    t1 = int(t1[1:])
    t2 = int(t2[1:])
    if t1 < t2:
        return 1
    return -1


changed = []
for i in range(len(tier) - 1):
    if Comp_Tier(tier[i], tier[i + 1]) == 1:
        changed.append(tier[i])
        changed.append(tier[i + 1])
if changed:
    print("KO")
    print(f"{changed[len(changed) - 1]} {changed[0]}")
else:
    print("OK")
