import sys


T = int(input())
for t in range(T):
    N = int(input())
    phones = []
    # 전화번호 입력
    for n in range(N):
        phones.append(sys.stdin.readline().rstrip().replace(" ", ""))
    # 오름차순 정렬
    phones = sorted(phones)
    # 만약 접두어가 존재하는 번호가 있다면 그 번호 이전의 번호가 접두사이다.
    for i in range(N - 1):
        length = len(phones[i])
        if phones[i] == phones[i + 1][:length]:
            print("NO")
            break
        if i == N - 2:
            print("YES")
