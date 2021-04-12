from sys import stdin, stdout
from itertools import  combinations #중복 조합

def dfs(idx, res, p, m, mul, div): #피연산자의 인덱스값, 현재 계산 결과, 남은 사칙연산 개수
  global max_res #전역 변수 선언
  global min_res

  if idx == n: #모든 계산을 완료했으면 이제는 우리가 돌아가야 할 시간~
    max_res = max(max_res, res)
    min_res = min(min_res, res)
    return

  if p: #plus 개수가 0 이상이면
    dfs(idx+1, res + operand[idx], p-1, m, mul, div)
  if m:
    dfs(idx+1, res - operand[idx], p, m-1, mul, div)
  if mul:
    dfs(idx+1, res * operand[idx], p, m, mul-1, div)
  if div: #나눗셈의 경우 c++14의 기준을 따른다
    tmp = res
    if res < 0:
      tmp = -(-res // operand[idx])  #파이썬에서 몫만 가지려면 // 사용!
    else:
      tmp = res // operand[idx]
    dfs(idx+1, tmp, p, m, mul, div-1)


n = int(stdin.readline())
operand = stdin.readline().split() #피연산자를 리스트로 받고
operand = list(map(int, operand)) #정수로 변환하여 저장

operator = stdin.readline().split()
operator = list(map(int, operator))

min_res = 1e9
max_res = -1e9
dfs(1, operand[0], operator[0], operator[1], operator[2], operator[3])

print(max_res)
print(min_res)