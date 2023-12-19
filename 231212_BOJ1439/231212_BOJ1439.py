# 뒤집기_BOJ1439

import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

S = sys.stdin.readline().strip()

count = 1
while (len(set(S)) != 1):
    next = '0' if S[0] == '1' else '1'
    
    count += 1
    S = S[S.find(next):]

print(count // 2)