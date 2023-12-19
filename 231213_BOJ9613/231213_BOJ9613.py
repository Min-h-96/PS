# GCD 합_BOJ9613

import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

t = int(sys.stdin.readline())
answers = []

for _ in range(t):
    lst = list(map(int, sys.stdin.readline().split()))
    n = lst[0]
    answer = 0
    
    for i in range(1, n):
        for j in range(i + 1, n + 1):
            answer += gcd(lst[i], lst[j])
    
    answers.append(answer)

for a in answers:
    print(a)