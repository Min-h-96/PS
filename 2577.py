# 백준 2577번 문제. 숫자의 개수

A = int(input())
B = int(input())
C = int(input())

result = A * B * C
str_result = str(result)

for i in range(10):
    count = 0
    for j in range(len(str_result)):
        if int(str_result[j]) == i:
            count += 1
    print(count)

"""
참고 : count 메소드를 이용한 간단한 코드

lst = list(map(int, str(A * B * C)))

for i in range(10):
    print(lst.count(i))
