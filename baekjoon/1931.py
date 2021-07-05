from sys import stdin, stdout

n = int(stdin.readline())  # 전체 회의의 개수
conf = []  # 회의 시간을 담는 리스트
answer = 0

for _ in range(n):
    start, end = map(int, stdin.readline().split())
    conf.append([start, end])

# 끝나는 시간 우선, 시작하는 시간을 다음 기준으로 정렬
# 1 2 / 2 2 인 경우 결과가 2가 나와야 함
conf.sort(key=lambda x: (x[1], x[0]))
pre = 0
for case in conf:
    if pre <= case[0]:
        answer += 1
        pre = case[1]

print(answer)