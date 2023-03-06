import sys
input = sys.stdin.readline
dx, dy = [1, 0, -1, 0, 1, 1, -1, -1], [0, 1, 0, -1, 1, -1, 1, -1]
mandarat = [list(input().rstrip().split()) for i in range(9)]
goal = []
for i in range(9):
    for j in range(9):
        if i == 4 and j == 4:
            continue
        if i % 3 == 1 and j % 3 == 1:
            tmp = []
            for k in range(8):
                nx, ny = i + dx[k], j + dy[k]
                tmp.append(mandarat[nx][ny])
            tmp.sort()
            goal.append([mandarat[i][j]] + tmp)
goal.sort()
for x in range(8):
    print(f"#{x + 1}. {goal[x][0]}")
    for y in range(1, 9):
        print(f"#{x + 1}-{y}. {goal[x][y]}")
