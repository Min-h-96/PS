# 백준 1316번 문제. 그룹 단어 체크
import sys

T = int(sys.stdin.readline())

count = 0
for i in range(T):
    C = sys.stdin.readline()
    x = '1'
    C_2 = []

    for j in C:
        if x == j:
            pass
        else:
            C_2.append(j)
        x = j
    for k in C_2:
        if C_2.count(k) > 1:
            T_F = False
            break
        else:
            T_F = True
    if T_F:
        count += 1

print(count)

# 64ms
