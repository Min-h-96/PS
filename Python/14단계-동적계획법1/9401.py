# 백준 9401번 문제.
def countNum(n):
    a, b = 0, 1
    for i in range(n):
        a, b = b, (a+b)%15746
    return b

print(countNum(int(input())))

# 29088KB 152ms

"""
def countNum(n):
    arr = [1, 2, 3]
    if n <= 3:
        if n == 1:
            return arr[0]
        elif n == 2:
            return arr[1]
        else:
            return arr[2]
    else:
        for i in range(0, n-3):
            arr[0] = arr[1]
            arr[1] = arr[2]
            arr[2] = (arr[0] + arr[1])%15746
        return arr[2]

N = int(input())

print(countNum(N))

29088KB 276ms
"""