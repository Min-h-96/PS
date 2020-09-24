# 백준 2562번 문제. 최댓값 위치 찾기

lst = []
for i in range(9):
    x = int(input())
    lst.append(x)
print(max(lst))
print(lst.index(max(lst))+1)
