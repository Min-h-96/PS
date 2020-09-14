# 백준 4344번 문제.
import sys

N = int(sys.stdin.readline())

for i in range(N):
    listScore = list(map(float, sys.stdin.readline().split()))
    avg = sum(listScore[1:])/len(listScore[1:])
    count = 0

    for j in listScore[1:]:
        if j > avg:
            count += 1
    print('{0:.3f}%'.format(count/len(listScore[1:])*100))

# 68ms
