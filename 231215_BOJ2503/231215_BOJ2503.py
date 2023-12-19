# 숫자 야구_BOJ2503

import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

from itertools import permutations

N = int(sys.stdin.readline())
nums = [i + 1 for i in range(9)]
total = list(permutations(nums, 3))

for _ in range(N):
    n, s, b = map(int, sys.stdin.readline().split())
    
    nums = []
    for num in list(str(n)):
        nums.append(int(num))
    
    tmp = total.copy()
    for t in total:
        c_s = 0
        c_b = 0
        for i in range(3):
            if (t[i] == nums[i]):
                c_s += 1
                continue
            if (t[i] in nums):
                c_b += 1
        
        if c_s != s or c_b != b:
            tmp.remove(t)
    
    total = tmp
    
print(len(total))