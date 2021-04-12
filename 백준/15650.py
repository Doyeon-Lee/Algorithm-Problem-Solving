from sys import stdin, stdout
from itertools import combinations #조합

n, m = stdin.readline().split()
n = int(n)
m = int(m)

num = [str(i+1) for i in range(n)]
comb = list(map(' '.join, combinations(num, m)))

for item in comb:
  print(item)