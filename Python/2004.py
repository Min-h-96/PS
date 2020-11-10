# 백준 2004번 문제. 조합 0의 개수
import sys

n, m = map(int, sys.stdin.readline().split())

count5 = 0
count2 = 0

for i in range(1, 14):
    count5 += int(n/(5**i))
    count5 -= int(m/(5**i))
    count5 -= int((n-m)/(5**i))

for i in range(1, 31):
    count2 += int(n/(2**i))
    count2 -= int(m/(2**i))
    count2 -= int((n-m)/(2**i))

if count2 <= count5:
    print(count2)
else:
    print(count5)

# 29088KB 72ms