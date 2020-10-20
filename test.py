import sys

N = int(sys.stdin.readline())
judge = []

for n in range(N):
    age, name = list(map(str, sys.stdin.readline().split()))
    user = [age.zfill(3), name]
    judge.append(user)

print(judge)
