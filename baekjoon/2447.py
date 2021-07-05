def draw_stars(star):
  l = len(star)
  matrix = []

	#모든 line 고려
  for i in range(l*3):
    #가운데 줄의 공백 처리
    if i // l == 1:
      matrix.append(star[i % l] + " " * l + star[i % l])
    else:
      matrix.append(star[i%l]* 3)
  return matrix

star = ["***", "* *", "***"]

n = int(input())
e = 0

#3^e == n
while n > 3:
  n = n / 3
  e += 1

for i in range(e):
  star = draw_stars(star)

for i in star:
  print(i)
 
#먼저 input 값이 3의 몇승인지 e를 구하고, 그 횟수만큼 재귀를 반복한다
#매번 새로운 리스트를 준비하고 append를 실행, 완성된 matrix를 리턴