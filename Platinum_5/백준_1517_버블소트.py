import sys
input = sys.stdin.readline
N = int(input())
seq = list(map(int, input().split()))
sorted_seq = sorted(seq)


def Merge_Sort(st, en):
    global cnt
    if st < en:
        mid = (st + en) // 2
        # 리프 노드부터 시작해야 하므로 재귀를 먼저 실행한다.
        Merge_Sort(st, mid)
        Merge_Sort(mid + 1, en)
        # a : 좌측 배열 인덱스, b : 우측 배열 인덱스
        a, b = st, mid + 1
        tmp = []
        while a <= mid and b <= en:
            if seq[a] <= seq[b]:
                tmp.append(seq[a])
                a += 1
            else:
                # 우측 배열의 숫자가 좌측 배열 숫자보다 작은 경우
                # 앞으로 몇 칸이나 이동하는지 누적해서 계산한다.
                tmp.append(seq[b])
                b += 1
                # mid + 1 은 중간 인덱스, a 는 현재 좌측 배열 맨 앞 인덱스값
                cnt += (mid + 1 - a)
        if a <= mid:
            tmp += seq[a:mid + 1]
        if b <= en:
            tmp += seq[b:en + 1]
        for i in range(len(tmp)):
            seq[st + i] = tmp[i]


cnt = 0
Merge_Sort(0, N - 1)
print(cnt)
