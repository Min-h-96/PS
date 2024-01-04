# Z_BOJ1074

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

N, r, c = map(int, sys.stdin.readline().split())
answer = 0

for n in range(N, 0, -1):
    if (n == 1):
        answer += r * 2 + c
        break
    if (r < 2**(n - 1) and c < 2**(n - 1)):
        continue
    
    if (r >= 2**(n - 1) and c >= 2**(n - 1)):
        answer += 2**(n - 1) * 2**(n - 1) * 3
        r -= 2**(n - 1)
        c -= 2**(n - 1)
    elif (r >= 2**(n - 1)):
        answer += 2**(n - 1) * 2**(n - 1) * 2
        r -= 2**(n - 1)
    elif (c >= 2**(n - 1)):
        answer += 2**(n - 1) * 2**(n - 1)
        c -= 2**(n - 1)
    
print(answer)