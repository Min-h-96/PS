# 백준 1330번 문제. 두 수 비교하기
a, b = map(int, input().split())
if a > b:
    print('>')
elif a == b:
    print('==')
else:
    print('<')
