from sys import stdin, stdout

n = int(stdin.readline())
num = list(map(int, stdin.readline().split()))
dp = [1] * n

for i in range(n):
    for j in range(i):
        if num[j] > num[i]:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp))