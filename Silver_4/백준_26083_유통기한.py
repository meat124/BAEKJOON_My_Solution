import sys
from datetime import date
input = sys.stdin.readline

Y, M, D = map(int, input().split())
today = date(2000 + Y, M, D)
result = ['invalid', 'unsafe', 'safe']
for i in range(int(input())):
    A, B, C = map(int, input().split())
    sum = 0
    for a, b, c in ((A, B, C), (C, B, A), (C, A, B)):
        # 날짜가 유효하지 않다면 date 객체 생성에서 에러가 발생하므로 try-except 를 사용한다.
        try:
            # 유통기한이 지나지 않았으면 2를 더하고, 유통기한이 지났으면 1을 더한다.
            sum += 1 + ((date(2000 + a, b, c) - today).days >= 0)
        except:
            pass
        # 유효한 날짜에서 유통기한이 지난 것이 하나라도 있다면 홀수이고 1과 &비트연산을 하면 True 이다.
        if sum & 1:
            break
    # sum & 1 이 성립하면 유통기한이 지난 것이므로 1이 되고 result[1] = unsafe 출력
    # sum > 0 이면 True(1) 이 되고, 거기에 2를 곱해서 2를 만든 후 >> result[2] = safe 출력한다.
    print(result[(sum & 1) or ((sum > 0) * 2)])
