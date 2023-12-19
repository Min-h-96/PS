# 색종이 만들기_BOJ2630

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

from collections import deque

white = 0
blue = 0
N = int(sys.stdin.readline())
paper = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
dq = deque([paper])

while (len(dq)):
    paper = dq.popleft()
    
    color = []
    for p in paper:
        color += set(p)
    
    n = len(paper)
    if (len(set(color)) == 2):
        for i in range(2):
            n1 = []
            n2 = []
            for j in range(n // 2):
                n1.append(paper[i * n // 2 + j][:n//2])
                n2.append(paper[i * n // 2 + j][n//2:])
            dq.append(n1)
            dq.append(n2)
    else:
        if (paper[0][0] == 0):
            white += 1
        else:
            blue += 1

print(white)
print(blue)