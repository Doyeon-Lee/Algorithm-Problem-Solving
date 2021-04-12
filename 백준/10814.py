n = int(input())
members = []

for _ in range(n):
  age, name = input().split()
  age = int(age) #왜 이 줄을 제외하면 틀리는 거지
  members.append([age, name])

members.sort(key = lambda x : x[0])

for member in members:
  print(member[0], member[1])
