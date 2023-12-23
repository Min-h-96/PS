# 트럭_BOJ13335

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

from collections import deque

n, w, l = map(int, sys.stdin.readline().split())
trucks = list(map(int, sys.stdin.readline().split()))
sum = 0

bridge = deque([0 for _ in range(w)])
time = 0
total = 0

for t in trucks:
    while (total + t - bridge[0] > l):
        total -= bridge.popleft()
        bridge.append(0)
        time += 1
        
    total -= bridge.popleft()
    bridge.append(t)
    total += t
    time += 1

while (set(bridge) != {0}):
    total -= bridge.popleft()
    bridge.append(0)
    time += 1

print(time)