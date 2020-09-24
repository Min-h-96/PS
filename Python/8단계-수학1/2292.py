# 백준 2292번 문제. 벌집
N = int(input())

start = 1
count = 1

if N == 1:
    print(1)
else:
    while True:
        end = start + (6*count)
        if N <= end:
            break
        count += 1
        start = end
    print(count+1)

# 72ms
