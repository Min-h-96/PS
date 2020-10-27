import sys
from itertools import combinations_with_replacement

input_val = list(map(int, sys.stdin.readline().split()))
N, M = input_val

def solve(remain):
    res = list(map(' '.join, combinations_with_replacement(remain, M)))
    print('\n'.join(res))

solve(map(str, list(range(1, N+1))))

num_list = [-1, 0, 1, 3, 4, 5, 9]

print(num_list)
# [-1, 0, 1, 3, 4, 5, 9]
print(" ".join(map(str, num_list)))