# 문자열 잘라내기_BOJ2866

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

R, C = map(int, sys.stdin.readline().split())
table = [sys.stdin.readline().strip() for _ in range(R)]
count = 0

lst = []
for j in range(C):
	string = ''
	for k in range(1, R):
		string += table[k][j]
	lst.append(string)

for i in range(R - 1):
	s = set()
	for l in lst:
		l = l[i:]
		s.add(l)
	
	if (len(s) != C):
		break
	else:
		count += 1

print(count)