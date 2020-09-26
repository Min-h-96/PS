# 백준 10951번 문제. A+B 4번쨰
import sys

while True:
    try:
        a, b = map(int, sys.stdin.readline().split())
        print(a+b)
    except:
        break

# 72ms

"""
몇 개의 테스트 케이스를 하는지 주어지지 않는 경우 EOF까지 받으면 된다.
이 때, try except 문으로 EOF까지 가서 에러가 뜰 경우 break로 빠져나오게 한다.
"""
