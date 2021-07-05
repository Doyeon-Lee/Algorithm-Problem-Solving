from sys import stdin, stdout
import heapq

heap = []

n = int(stdin.readline())
for _ in range(n):
    x = int(stdin.readline())
    if x > 0:
        heapq.heappush(heap, -x)
    else:
        if len(heap) == 0:
            print(0)
        else:
            print(-heapq.heappop(heap))