# 백준 10039번 문제. 평균 점수
sum = 0
for i in range(5):
    x = int(input())
    if x > 40:
        sum += x
    else:
        sum += 40
print(int(sum/5))
