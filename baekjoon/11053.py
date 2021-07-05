from sys import stdin, stdout

n = int(stdin.readline())
num = list(map(int, stdin.readline().split()))
arr = [1 for i in range(n)]

for i in range(n):
    for j in range(i):
        if num[i] > num[j]:
            arr[i] = max(arr[i], arr[j]+1)

print(max(arr))