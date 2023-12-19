# 수리공 항승_BOJ1449

import sys
sys.stdin = open('input.txt')
input = sys.stdin.readline

N, L = map(int, sys.stdin.readline().split())
water = sorted(list(map(int, sys.stdin.readline().split()))) # 오름차순으로 정렬
answer = 0
lst = []

for w in water:
    if (w in lst): # 이미 lst 에 값이 있다면 해당 부분은 테이프가 이미 붙여진 곳이므로 다음으로 넘어간다.
        continue
    
    for i in range(w, w + L): # 붙여진 테이프 여분의 길이가 막는 모든 곳을 lst 에 추가
        lst.append(i)
    answer += 1 # 테이프의 개수 +1

print(answer)