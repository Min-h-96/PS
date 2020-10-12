# 백준 1436번 문제
import sys

N = int(sys.stdin.readline())

lst = []
num = 1

while len(lst) < N:
    if '666' in str(num):
        lst.append(num)
    num += 1

print(lst[len(lst)-1])

# 1148ms


"""
import sys

N = int(sys.stdin.readline())

lst = []

for i in range(2699999):
    if '666' in str(i):
        lst.append(i)

print(lst[N-1])

# 824ms
"""
