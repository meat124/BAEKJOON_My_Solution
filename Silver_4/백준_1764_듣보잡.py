N, M = input().split()
a = set()
b = set()
for i in range(int(N)):
    a.add(input())
for i in range(int(M)):
    b.add(input())
# sorted 는 정렬된 리스트를 리턴한다.
# a & b 는 교집합이므로 공통된 요소가 존재하는 리스트를 구할 수 있다.
result = sorted(list(a & b))
print(len(result))
for i in result:
    print(i)
