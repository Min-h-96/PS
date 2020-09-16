# 백준 1157번 문제. 단어 공부
import sys

X = sys.stdin.readline()
count = 0
most = 0

for i in range(26):
    if X.upper().count(chr(65+i)) > count:
        most = 65+i
        count = X.upper().count(chr(65+i))
    elif X.upper().count(chr(65+i)) == count:
        most = 63
print(chr(most))

# 144ms
