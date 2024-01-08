# 아이폰 9S_BOJ5883

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
B = []
answer = 0

for _ in range(N):
    B.append(int(sys.stdin.readline()))

S = set(B)

for s in S:
    b = [i for i in B if i != s]
    
    cur = -1
    a = 0
    for c in b:
        if (c != cur):
            answer = max(a, answer)
            a = 1
            cur = c
        else:
            a += 1
        
    answer = max(a, answer)

if (len(B) == 1):
    print(1)
else:
    print(answer)