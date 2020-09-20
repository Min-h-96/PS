# 백준 1065번 문제. 한수
def solve(n):
    count = 0
    for i in range(1, n+1):
        m = list(map(int, str(i)))
        if len(m) <= 2:
            count += 1
        elif len(m) == 3:
            if m[0] - m[1] == m[1] - m[2]:
                count += 1
            else:
                pass
    print(count)


N = int(input())
solve(N)

# 72ms

"""
다른 분이 푼 방법
print(sum((N//100-N//10%10==N//10%10-N%10)|(N<100)for N in range(1,int(input())+1)))

이해를 위한 풀이
if N = 123
print(N//100)  # 백의 자리
print(N//10)  # 백의자리*10 + 십의자리*1
print(N//100-N//10)  # 백의자리*10 + (백의자리-십의자리)
print(N//100-N//10 % 10)  # 백의자리 - 십의자리

print(N//10)  # 백의자리*10 + 십의자리*1
print(N//10 % 10)  # 십의자리
print(N//10 % 10-N)  # 십의자리*1 - 원래자연수(백의자리*100 + 십의자리*10 + 일의자리*1)
# -백의자리*100 - 십의자리*10 + (십의자리 - 일의자리)
print(N//10 % 10-N % 10)  # 십의자리 - 일의자리

"""
