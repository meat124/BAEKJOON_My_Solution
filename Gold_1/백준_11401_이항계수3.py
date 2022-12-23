N, K = map(int, input().split())
p = int(1e9 + 7)


def factorial(N):
    n = 1
    for i in range(2, N + 1):
        n = (n * i) % p
    return n


def Square(n, k):
    # n^k를 리턴
    if k == 0:
        return 1
    if k == 1:
        return n
    tmp = Square(n, k//2)
    if k % 2:
        return tmp * tmp * n % p
    else:
        return tmp * tmp % p


# 모듈러 연산의 분배법칙은 나눗셈에서는 적용되지 않으므로
# 분모의 부분을 페르마의 소정리를 이용하여 자연수 거듭제곱 형태로 바꿔준다.
# 즉 N!((N-K)!K!)^(-1) % p 는
# a^(p-2) 는 a^(-1) (mod p) 와 합동이므로
# >> N!((N-K)!K!)^(p-2) % p 와 같다.
top = factorial(N) % p
bot = factorial(N-K) * factorial(K) % p
print(top * Square(bot, p-2) % p)
