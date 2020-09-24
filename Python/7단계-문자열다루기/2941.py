# 백준 2941번 문제. 크로아티아 알파벳
import sys

C = sys.stdin.readline()

for i in ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']:
    if i in C:
        C = C.replace(i, '1')

print(len(C)-1)

# 64ms
