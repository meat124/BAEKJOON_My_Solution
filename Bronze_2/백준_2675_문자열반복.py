for T in range(int(input())):
    INPUT = input().split()
    R = int(INPUT[0])
    S = INPUT[1]
    total_S = ""
    for i in range(len(S)):
        for j in range(R):
            total_S += S[i]
    print(total_S, end='')
    print()
