# DNA 비밀번호_BOJ12891

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

S, P = map(int, sys.stdin.readline().split())
dna = list(sys.stdin.readline().strip())
n_a, n_c, n_g, n_t = map(int, sys.stdin.readline().split())
answer = 0
dic = {'A': 0, 'C': 0, 'G': 0, 'T': 0}

for i in range(P):
    dic[dna[i]] += 1

if (dic['A'] >= n_a and dic['C'] >= n_c and dic['G'] >= n_g and dic['T'] >= n_t):
    answer += 1

for i in range(P, S):
    dic[dna[i]] += 1
    dic[dna[i - P]] -= 1
        
    if (dic['A'] >= n_a and dic['C'] >= n_c and dic['G'] >= n_g and dic['T'] >= n_t):
        answer += 1

print(answer)