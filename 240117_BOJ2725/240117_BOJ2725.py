# 보이는 점의 개수_BOJ2725

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

C = int(sys.stdin.readline())
s = set([1])
answers = [0, 3]

count = 3
for i in range(2, 1001):
    for j in range(1, i):
        # y 축 수평
        if (j / i not in s):
            s.add(j / i)
            count += 1
        
        # x 축 수형
        if (i / j not in s):
            s.add(i / j)
            count += 1
        
    answers.append(count)

for _ in range(C):
    print(answers[int(sys.stdin.readline())])