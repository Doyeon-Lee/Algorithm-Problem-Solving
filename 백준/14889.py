from sys import stdin, stdout
from itertools import combinations

n = int(stdin.readline())
num = [i for i in range(n)]

w = [] #weight
for _ in range(n):
    tmp = stdin.readline().split()
    tmp = list(map(int, tmp))
    w.append(tmp)

comb = list(combinations(num, n//2)) #조합 object이기 떄문에 list 변환 필요
diff = 1e9 #float('inf')

for start in comb: #솔루션 참고
    link = list(set(num)-set(start)) #전체 집합에서 start 제외

    start_pair = list(combinations(start, 2)) #두명씩 값을 더하기 위해
    link_pair = list(combinations(link, 2))

    start_score = 0
    for x, y in start_pair:
        start_score += (w[x][y] + w[y][x])

    link_score = 0
    for x, y in link_pair:
        link_score += (w[x][y] + w[y][x])

    buf = abs(start_score - link_score) #절댓값 차이
    if buf < diff:
        diff = buf
		#if diff = 0:
		#break

print(diff)