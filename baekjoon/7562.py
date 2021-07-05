from sys import stdin, stdout

i_moves = [-2, -2, -1, -1, 1, 1, 2, 2]
j_moves = [-1, 1, -2, 2, -2, 2, -1, 1]

def bfs():
    while len(stack) > 0:
        x, y = stack.pop(0)  # 스택에서 하나 뽑는다
        if x == endx and y == endy:  # from solution
            return

        for k in range(8):
            i = x + i_moves[k]
            j = y + j_moves[k]
            if 0 <= i < m and 0 <= j < m and chess[i][j] == 0:  # 0이면 실행
                stack.append((i, j))
                chess[i][j] = chess[x][y] + 1


n = int(stdin.readline())

for _ in range(n):
    m = int(stdin.readline())
    startx, starty = map(int, stdin.readline().split())
    endx, endy = map(int, stdin.readline().split())
    chess = list(list(0 for _ in range(m)) for _ in range(m))

    if startx == endx and starty == endy:  # 시작=끝 예외처리
        print(0)
        continue

    queue = [(startx, starty)]
    bfs()
    print(chess[endx][endy])