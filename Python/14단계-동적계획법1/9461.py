# 백준 9461번 문제. 파도반 수열
def padoban(n):
    arr = [0, 1, 1, 1]
    for i in range(2, n):
        arr.append(arr[i-1] + arr[i])
    return arr[n]

N = int(input())
for i in range(N):
    print(padoban(int(input())))

# 29088KB 80ms