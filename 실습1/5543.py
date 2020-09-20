# 백준 5543번 문제. 상근날드
lst = []
for i in range(5):
    lst.append(int(input()))
print(min(lst[:3])+min(lst[3:])-50)
