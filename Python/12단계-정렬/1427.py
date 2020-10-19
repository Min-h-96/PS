# 백준 1427번 문제. 수 정렬하기
import sys

N = sys.stdin.readline()
num_lst = []
new_num = ''

for i in range(len(N)-1):
    num_lst.append(N[i])

num_lst.sort(reverse=True)
for i in range(len(num_lst)):
    new_num += num_lst[i]

print(int(new_num))

# 64ms 29380KB
