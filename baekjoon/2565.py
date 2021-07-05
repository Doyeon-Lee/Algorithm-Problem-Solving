from sys import stdin, stdout

n = int(stdin.readline())
arr = []

for _ in range(n):
    a, b = map(int, stdin.readline().split())
    arr.append((a, b))  # 튜플 써보고 싶었다

arr.sort(key=lambda x: x[0])  # 튜플 정렬도 같은 방식; a전깃줄 기준으로 정렬
dp = [1 for _ in range(n)]

for i in range(n):
    for j in range(i):
        if arr[j][1] < arr[i][1]:
            dp[i] = max(dp[i], dp[j] + 1)
print(n - max(dp))