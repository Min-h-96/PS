# 소수의 자격_BOJ6219

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

A, B, D = map(int, sys.stdin.readline().split())
n = 4000000
p = [False, False] + [True]*(n - 1)
primes = []
answer = 0

for i in range(2, n + 1):
  if p[i]:
    primes.append(i)
    for j in range(2*i, n+1, i):
        p[j] = False
        
for p in primes:
    if (p > B):
        break
    if (p < A):
        continue
    
    if (str(D) in str(p)):
        answer += 1

print(answer)