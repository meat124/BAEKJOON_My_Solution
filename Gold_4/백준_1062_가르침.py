from itertools import combinations
import sys
from string import ascii_lowercase
N, K = map(int, sys.stdin.readline().split())
K -= 5
if K < 0:
    print(0)
    exit(0)
# must_know 가 dict 로 선언되어야 변하지 않는다는 보장을 얻을 수 있다.
must_know = {'a', 'c', 't', 'i', 'n'}
words = []
alpha = set(ascii_lowercase) - must_know
result = 0
for i in range(N):
    # a,c,t,i,n 을 입력에서 제거한다.
    word = set(sys.stdin.readline().rstrip()) - must_know
    words.append(word)
for c in combinations(alpha, K):
    cur = 0
    c = set(c)
    for word in words:
        if word & c == word:
            cur += 1
    result = max(result, cur)
print(result)
