# 백준 10817.py 세 정수 중 두 번째로 큰 정수 출력
import statistics

lst = map(int, input().split())
print(statistics.median(list(lst)))
