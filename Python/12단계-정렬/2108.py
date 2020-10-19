# 백준 2108번 문제. 통계학
import sys
from collections import Counter

N = int(sys.stdin.readline())
lst = []

for n in range(N):
    x = int(sys.stdin.readline())
    lst.append(x)

lst.sort()

order = Counter(lst).most_common()
max_mode = order[0][1]
modes = []
for i in order:
    if i[1] == max_mode:
        modes.append(i[0])

print(round(sum(lst)/len(lst)))
print(lst[int(N/2)])
print(modes[1] if len(modes) > 1 else modes[0])
print(lst[N-1]-lst[0])

# 592ms 52156KB
