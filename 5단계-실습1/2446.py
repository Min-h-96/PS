# 백준 2446번 문제. 별 찍기 - 9
N = int(input())
count = N-2

for i in range(1, 2*N):
    if 0 < i <= N:
        star = '*'*(2*N-(2*i-1))
        print(star.rjust(2*N-i))
    else:
        star = '*'*(i-count)
        count -= 1
        print(star.rjust(i))

# * i 공백
# 9 1 9
# 7 2 8
# 5 3 7
# 3 4 6
# 1 5 5
# 3 6 6 i-3
# 5 7 7 i-2
# 7 8 8 i-1
# 9 9 9 i-0

# 7 1 7
# 5 2 6
# 3 3 5
# 1 4 4
# 3 5 5 i-2
# 5 6 6 i-1
# 7 7 7 i-0
