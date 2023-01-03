import sys
input = sys.stdin.readline


def Get_Measure(n):
    # n의 약수들의 리스트를 리턴한다.
    ret = []
    for i in range(1, int(n**(1/2)) + 1):
        if n % i == 0:
            ret.append(i)
            if i**2 != n:
                ret.append(n//i)
                if i == 1:
                    ret.pop()
    return ret


def Is_Abundant_Number(n):
    # 과잉수면 True, 아니면 False 를 리턴한다.
    if sum(Get_Measure(n)) > n:
        return True
    return False


T = int(input())
for i in range(T):
    tc = int(input())
    measures = Get_Measure(tc)
    flag = True
    for m in measures:
        if Is_Abundant_Number(m):
            flag = False
    if sum(measures) > tc and flag:
        print("Good Bye")
    else:
        print("BOJ 2022")
