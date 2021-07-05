from sys import stdin, stdout
from itertools import permutations #순열

n, m = stdin.readline().split()
n = int(n)
m = int(m)

num = [str(i+1) for i in range(n)] #1부터 n까지 저장

perm = list(map(' '.join, permutations(num, m)))

for item in perm:
  print(item)