# dfs 방식
# from sys import stdin
# import sys
# sys.setrecursionlimit(10**9) # 안넣으면 런타임 에러남

# xpos = [1, -1, 0, 0]
# ypos = [0, 0, 1, -1]


# def dfs(i, j):
#     global answer
#     if i == m-1 and j == n-1:
#         answer += 1

#     for idx in range(4):
#         _x = j + xpos[idx]
#         _y = i + ypos[idx]
# 				# 범위를 벗어나면 실행하지 않음
# 		    if 0 <= _y < m and 0 <= _x < n:
# 		            if _map[i][j] > _map[_y][_x] and not visit[_y][_x]:
# 		                #visit[_y][_x] = True
# 		                dfs(_y, _x)
# 		                #visit[_y][_x] = False


# m, n = map(int, stdin.readline().split())
# _map = []
# for i in range(m):
#     _map.append(list(map(int, stdin.readline().split())))

# visit = [[False for _ in range(n)] for _ in range(m)]
# visit[0][0] = True
# answer = 0
# dfs(0, 0)
# print(answer)


#dfs + dp 방식
from sys import stdin
import sys
sys.setrecursionlimit(10**9)
xpos = [1, -1, 0, 0]
ypos = [0, 0, 1, -1]


# dp[i][j]란 해당 칸에서 오른쪽 아래의 마지막 칸까지 갈 수 있는 경우의 수
def dfs(i, j):
    # 마지막 칸에서 마지막 칸으로 가는 경우의 수=1
    if i == m-1 and j == n-1:
        return 1

    # 가본적 없는 칸이라면, 즉 마지막 칸에서 1을 리턴할 때까지 호출된다
    if dp[i][j] == -1:
        dp[i][j] = 0
        # 4가지 방향을 모두 시도해보며
        for idx in range(4):
            _x = j + xpos[idx]
            _y = i + ypos[idx]

            # 범위 내이고 현재 칸보다 더 작은 수라면
            if 0 <= _y < m and 0 <= _x < n:
                if _map[i][j] > _map[_y][_x]:
                    # 해당 칸을 통해 이동할 수 있는 경우의 수를 더한다
                    dp[i][j] += dfs(_y, _x)
    return dp[i][j]


m, n = map(int, stdin.readline().split())
_map = []
for i in range(m):
    _map.append(list(map(int, stdin.readline().split())))
dp = [[-1 for _ in range(n)] for _ in range(m)]
print(dfs(0, 0))