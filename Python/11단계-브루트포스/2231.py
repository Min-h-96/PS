# 백준 2231번 문제. 분해합
import sys

N = int(sys.stdin.readline())

for i in range(int(N/2), N):
    sum = i
    con = str(i)
    for c in con:
        sum += int(c)
    if sum == N:
        print(i)
        exit(0)
print(0)

# 1008ms

# for i in range(int(2*N/3), N): 672ms
# 브르투포스 체크 범위를 줄일 수록 시간이 현저하게 줄어듬

"""
for i in range(N):
    sum = i
    con = str(i)
    for c in con:
        sum += int(c)
    if sum == N:
        print(i)
        exit(0)
print(0)

# 1840ms
"""
