# 백준 3052번 문제. 나머지
lst = []
for i in range(10):
    x = int(input())
    remain = x % 42
    if remain in lst:
        pass
    else:
        lst.append(remain)
print(len(lst))

# 68ms

"""
다른 분의 참고 코드 52ms
b = [int(input())%42 for i in range(10)]
print(len(set(b)))
"""
