# 백준 1193번 문제. 분수 찾기
import sys

X = int(sys.stdin.readline())
i = 1

if X > 1:
    while X > i:
        X -= i
        i += 1
    if i % 2 == 0:
        a = X
        b = i-X+1
        print(str(a)+'/'+str(b))
    else:
        a = i-X+1
        b = X
        print(str(a)+'/'+str(b))
else:
    print('1/1')

# 60ms
