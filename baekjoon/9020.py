#범위 내의 소수 구하기
test_case = int(input())

for case in range(test_case):
  n = int(input())

  prime = [True] * (n+1)
  for i in range(2, int(n**0.5) + 1):
    if prime[i]:
      for j in range(2*i, n+1, i):
          prime[j] = False

  #n/2부터 시작; a가 소수이고 n-a가 소수라면 ok

  quot = n // 2 # // 연산자는 소수점 이하의 수를 버린다
  for i in range(quot, 1, -1): #세번째 인수는 숫자 사이의 거리를 뜻함
    if prime[i] and prime[n-i]:
      print(i, n-i)
      break
	  
#1929번에서 소수를 구하는 방식을 그대로 가져옴
#원래는 중간값부터 두 값을 증감시키며 찾으려 했으나
#a+b = n일때 a가 소수이면 b(=n-a)도 소수임을 참고