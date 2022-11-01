from collections import Counter
N, S = map(int, input().split())
seq = list(map(int, input().split()))


def Subsum(st, en):
    ret = [0]
    for i in range(en - 1, st - 1, -1):
        for j in range(len(ret)):
            ret.append(seq[i] + ret[j])
    return ret


l_subsum, r_subsum = Subsum(0, N//2), Subsum(N//2, N)
subsum_cnt = Counter(r_subsum)  # r_subsum 에 있는 원소들의 개수를 딕셔너리로 만듦
print(sum(subsum_cnt[S - i] for i in l_subsum) - (1 if S == 0 else 0))
