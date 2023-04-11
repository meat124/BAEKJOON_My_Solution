from collections import Counter
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
use = list(map(int, input().split()))
use_cnt = Counter(use)
if len(use_cnt.keys()) <= N:
    print(0)
else:
    use_turn = dict()
    for i in range(K - 1, -1, -1):
        if use[i] in use_turn:
            use_turn[use[i]].append(i + 1)
        else:
            use_turn[use[i]] = [i + 1]
    cur = []
    result = 0
    for i in range(K):
        use_turn[use[i]].pop()
        # 이미 멀티탭에 꽂혀있다면
        if use[i] in cur:
            continue
        # 꽂혀있지 않고
        # 멀티탭에 빈 곳이 있다면
        if len(cur) < N:
            cur.append(use[i])
        # 꽂혀있지 않고
        # 멀티탭에 빈 곳이 없다면, 스케줄링 시작
        else:
            # 1. 앞으로 사용하지 않는 전기용품, 2. 가장 나중에 사용하는 전기용품
            # 앞으로 남은 사용횟수
            recent = -1
            v = -1
            for j, val in enumerate(cur):
                if len(use_turn[val]) == 0:
                    v = val
                    break
                if use_turn[val][-1] > recent:
                    recent = use_turn[val][-1]
                    v = val
            cur.remove(v)
            result += 1
            cur.append(use[i])
    print(result)
