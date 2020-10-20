# 백준 10814번 문제. 나이순 정렬
import sys
from operator import itemgetter

if __name__ == "__main__":
    N = int(sys.stdin.readline())
    judge = []

    for n in range(N):
        age, name = list(map(str, sys.stdin.readline().split()))
        user = [int(age), name]
        judge.append(user)

    judge = sorted(judge, key=itemgetter(0))

    for n in range(N):
        print(judge[n][0], judge[n][1])

# 452ms 45680KB
