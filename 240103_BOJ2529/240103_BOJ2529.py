# 부등호_BOJ2529

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

from itertools import permutations

k = int(sys.stdin.readline())
signs = sys.stdin.readline().strip().split()

def comp(a, b, s):
    if (s == '>'):
        return a > b
    else:
        return a < b
    
def calc(nums, perm):
    for p in perm:
        flag = True
        for i in range(len(p) - 1):
            flag = comp(p[i], p[i + 1], signs[i])
            if (flag == False):
                break
            
        if (flag):
            print(''.join(str(n) for n in p))
            break

nums = [i for i in range(9, -1, -1)]
perm = permutations(nums, k + 1)
calc(nums, perm)

nums = [i for i in range(10)]
perm = permutations(nums, k + 1)
calc(nums, perm)