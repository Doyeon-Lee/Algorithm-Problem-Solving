from sys import stdin

# 숫자를 문자열로 변환
n = int(stdin.readline())
nums = stdin.readline().split()

# dp로 팰린드롬인지 판단
dp = [[0 for _ in range(n)] for _ in range(n)]
# substr 의 길이가 1 혹은 2일 경우 초기화
for i in range(n):
    dp[i][i] = 1
    if i < n-1 and nums[i] == nums[i+1]:
        dp[i][i+1] = 1

# substr의 길이가 3이상일 경우 dp[i:j] 가 팰린드롬인지 여부는
# dp[i+1:j-1]가 펠린드롬이고, nums[i] == nums[j]인지에 달려있다
for i in range(n-3, -1, -1):
    for j in range(i, n):
        if dp[i+1][j-1] and nums[i] == nums[j]:
            dp[i][j] = 1

# 배열에서 start, end에 해당하는 값을 출력
m = int(stdin.readline())
for _ in range(m):
    s, e = map(int, stdin.readline().split())
    print(dp[s-1][e-1])