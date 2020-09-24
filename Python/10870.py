# 피보나치 수 5
def fibo5(n):
    if n == 0:
        return 0
    if n == 1:
        return 1

    return fibo5(n-1) + fibo5(n-2)


print(fibo5(int(input())))
