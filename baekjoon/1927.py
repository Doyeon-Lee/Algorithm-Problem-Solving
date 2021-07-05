from sys import stdin, stdout
import heapq

heap = []

n = int(stdin.readline())
for _ in range(n):
    x = int(stdin.readline())
    if x == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(heapq.heappop(heap))
    else:
        heapq.heappush(heap, x)