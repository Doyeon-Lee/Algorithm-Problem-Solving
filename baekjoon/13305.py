from sys import stdin, stdout

n = int(stdin.readline())
dist = list(map(int, stdin.readline().split()))
cost = list(map(int, stdin.readline().split())) #마지막거 필요 없는거 아니냐

total_dist = sum(dist)
min_cost = cost[0]
answer = min_cost * total_dist

for i in range(1, n):
    total_dist -= dist[i - 1]
    if min_cost > cost[i]:
        answer -= (total_dist * min_cost)
        min_cost = cost[i]
        answer = answer + total_dist * min_cost

print(answer)