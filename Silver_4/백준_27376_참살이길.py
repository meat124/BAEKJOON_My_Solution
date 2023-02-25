import sys
input = sys.stdin.readline
n, k = map(int, input().split())
light = []
for i in range(k):
    light.append(list(map(int, input().split())))
light.sort()
cur_time = 0
cur_coord = 0
for i in range(k):
    cur_time += light[i][0] - cur_coord
    if cur_time < light[i][2]:
        cur_time = light[i][2]
    # 1과 and 연산 True 이면 빨간불
    elif (cur_time - light[i][2])//light[i][1] & 1:
        cur_time += light[i][1] - ((cur_time - light[i][2]) % light[i][1])
    cur_coord = light[i][0]
cur_time += n - cur_coord
print(cur_time)
