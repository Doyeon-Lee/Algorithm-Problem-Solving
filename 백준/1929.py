m, n = input().split()
m = int(m)
n = int(n) + 1

prime = [True] * n
#n의 제곱근까지만 검사!<<시간초과 솔루션
for i in range(2, int(n**0.5) + 1):
  if prime[i]:
    for j in range(2*i, n, i):
        prime[j] = False
            
for i in range(m, n):
  if i > 1 and prime[i] == True:
    print(i)
	
# 처음에 에라토스테네스의 체를 이용했으나 시간초과
# →솔루션 검색; 반복문 범위를 제곱근과 2*i 등으로 제한
# prime = list(True for i in range(n)) 도 가능