n = int(input())

bulk = [] #[x, y]를 저장할 리스트
rank = [] #덩치등수를 저장할 리스트

for i in range(n):
  x, y = input().split(' ')
  x = int(x)
  y = int(y)

  if not bulk: #리스트가 비어있으면(첫 데이터면 삽입)
    bulk.append([x, y])
    rank.append(1)
    continue

  cur_cnt = 1 #현재 입력하는 사람의 등수
  for j in range(len(bulk)):
    #반복하면서 인덱스 값이 현재값보다 크면 rank++
    if bulk[j][0] < x and bulk[j][1] < y:
      rank[j] += 1
    if bulk[j][0] > x and bulk[j][1] > y:
      cur_cnt += 1

  bulk.append([x, y])
  rank.append(cur_cnt)

for i in range(n):
  print(rank[i], end=" ")