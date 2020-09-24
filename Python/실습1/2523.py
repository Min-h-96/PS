# 백준 2523번 문제. 별 찍기 - 13
N = int(input())
count = 0
for i in range(1, 2*N):
    if 0 < i <= N:
        print('*'*i)
    else:
        count += 1
        print('*'*(i-(2*count)))
