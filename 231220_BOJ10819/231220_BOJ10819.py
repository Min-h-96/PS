# 차이를 최대로_BOJ10819

import sys
# sys.stdin = open('input.txt')
input = sys.stdin.readline

N = int(sys.stdin.readline())
nums = sorted(list(map(int, sys.stdin.readline().split())))
answer = 0

from itertools import permutations

p = list(permutations(nums))

for nums in p:
    a = 0
    for i in range(N - 1):
        a += abs(nums[i] - nums[i + 1])
    
    answer = a if a > answer else answer

print(answer)