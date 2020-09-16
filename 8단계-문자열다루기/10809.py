# 백준 10809번 문제. 알파벳 찾기
import sys

S = sys.stdin.readline()

for i in range(26):
    if chr(97+i) in S:
        print(S.index(chr(97+i)), end=" ")
    else:
        print(-1, end=" ")

# 64ms

"""
find 함수를 이용하면 조건문을 활용할 필요없이 해당 string이 없을경우
-1을 반환해준다.
"""
