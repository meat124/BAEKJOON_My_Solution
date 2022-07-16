import sys
from collections import deque
for T in range(int(input())):
    func_p = sys.stdin.readline()
    num_cnt = int(input())  # 배열에 들어있는 수의 개수
    arr = input()
    if arr == "[]":
        arr = deque()
    else:
        arr = arr[1:-1].split(",")  # 양쪽 [] 제거하고 , 기준으로 분리
        arr = deque(arr)
    shift = 1  # 1 은 첫 원소 제거, -1 은 마지막 원소 제거
    flag = False
    for i in range(len(func_p)):
        if func_p[i] == 'R':
            shift *= (-1)
        elif func_p[i] == 'D':
            if len(arr) == 0:
                flag = True
                break
            if shift == 1:
                arr.popleft()
            else:
                arr.pop()
    if flag:
        print("error")
    else:
        if func_p.count('R') % 2 == 1:
            arr.reverse()
            num = ",".join(arr)
            print("["+num+"]")
        else:
            num = ",".join(arr)
            print("["+num+"]")
