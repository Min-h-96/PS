# 에너지 모으기_BOJ16198

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
W = list(map(int, sys.stdin.readline().split()))
answer = 0

def recursive(s):
    global answer
    
    if (len(W) == 2):
        answer = max(answer, s)
        return
    
    for i in range(1, len(W) - 1):
        t = W[i - 1] * W[i + 1]
        p = W.pop(i)
        recursive(s + t)
        W.insert(i, p)

recursive(0)
print(answer)