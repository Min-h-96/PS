def factorial(n):
    if n == 1 or n == 0:
        return 1
    return n * factorial(n-1)

N = factorial(int(input()))
x = str(N)

count = 0
for i in range(len(x)-1, -1, -1):
    if x[i] != '0':
        break
    else:
        count += 1
print(count)

# 29404KB 68ms

# 다른 아이디어 : 팩토리얼로 곱해지는 5의 개수를 세기