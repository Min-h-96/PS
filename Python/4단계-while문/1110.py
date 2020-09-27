# 백준 1110번 문제. 더하기 사이클
N = input()
M = N
count = 0

while True:
    if int(M) < 10:
        x = int(M)
        M = str(x)+str(x)
        count += 1
    else:
        x = int(M[0])+int(M[1])
        if x < 10:
            M = M[1]+str(x)
            count += 1
        else:
            M = M[1]+str(x-10)
            count += 1
    if int(N) == int(M):
        print(count)
        break

# 64ms
