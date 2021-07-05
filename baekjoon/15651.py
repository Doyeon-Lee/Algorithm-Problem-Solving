from sys import stdin, stdout
from itertools import product #중복 순열

n, m = stdin.readline().split()
n = int(n)
m = int(m)

num = [i+1 for i in range(n)]
# num = list(range(1, n+1)) 라고 쓸 수도 있음.

for item in product(num, repeat=m): #num에서 m번만큼 반복해서 m개 뽑기
  for i in range(m):
    print(item[i], end=" ")
  print() #마지막에만 줄 변환