from sys import stdin, stdout
from itertools import  combinations_with_replacement #중복 조합

n, m = stdin.readline().split()
n = int(n)
m = int(m)

num = [i+1 for i in range(n)]

for item in combinations_with_replacement(num, m): #위에서 repeat가 빠졌을 뿐 m번 반복
  for i in range(m):
    print(item[i], end=" ")
  print()