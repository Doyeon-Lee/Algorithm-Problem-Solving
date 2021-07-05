n = int(input())
words = []

for _ in range(n):
  w = input()
  words.append(w)

words.sort(key = lambda word : (len(word), word))
tmp = ""

for word in words:
  if tmp == word:
    continue
  print(word)
  tmp = word