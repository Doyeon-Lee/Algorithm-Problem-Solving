from sys import stdin, stdout


def dfs(x):
    global cnt
    if x == n:
        cnt += 1
        return

    for i in range(n):
        chess[x] = i  # 한 행에 퀸을 놓을 위치 번호만 바뀌므로 따로 초기화 필요x
        if check(x):
            dfs(x+1)


def check(x):
    for i in range(x):
        if chess[x] == chess[i] or abs(chess[x] - chess[i]) == x-i:
            return False
    return True


n = int(stdin.readline())
cnt = 0
chess = [0] * n  # i번째 행 chess[i]번째 열에 체스 놓음

dfs(0)
print(cnt)