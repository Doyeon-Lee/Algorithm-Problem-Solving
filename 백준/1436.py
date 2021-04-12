n = int(input())

cnt = 0
num = 666
six = "666"

while cnt < n:
  if six in str(num):
    cnt += 1
  num += 1

print(num-1)