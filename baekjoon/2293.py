# 시간 초과
# from sys import stdin
# from queue import PriorityQueue

# def recursive(num):
#     global answer
#     if num == 0:
#         answer += 1
#         return
#     elif que.qsize() == 1:
#         item = -que.get()
#         if num % item == 0:
#             answer += 1
#         que.put(-item)
#         return

#     item = -que.get()
#     quot = num // item
#     for i in range(quot+1): # 0포함
#         tmp = num - i*item
#         if tmp >= 0: recursive(tmp)
#     que.put(-item)


# n, k = stdin.readline().split()
# n = int(n); k = int(k)
# que = PriorityQueue()
# answer = 0

# for i in range(n):
#     tmp = stdin.readline()
#     que.put(-int(tmp))

# recursive(k)
# print(answer)


# dp 방식
from sys import stdin

n, k = map(int, stdin.readline().split())
coins = [] #동전 리스트 저장
for _ in range(n):
    coins.append(int(stdin.readline()))

#1원부터 k원까지 만들 수 있는 경우의 수를 저장한다
cases = [0 for _ in range(k+1)] #첫 시작을 제외한 k개 할당
cases[0] = 1 #연산을 시작하기 위함

for coin in coins:
    for i in range(coin, k+1):
        cases[i] += cases[i-coin]

print(cases[k])