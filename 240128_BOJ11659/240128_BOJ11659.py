# 구간 합 구하기 4_BOJ11659

import sys
# sys.stdin = Aopen('input.txt')
input = sys.stdin.readline

N, M = map(int, sys.stdin.readline().split())
nums = list(map(int, sys.stdin.readline().split()))
sums = [0]

sum = 0
for n in nums:
	sum += n
	sums.append(sum)

for _ in range(M):
	i, j = map(int, sys.stdin.readline().split())
	print(sums[j] - sums[i - 1])

# N 과 M 의 입력값 범위가 둘 다 10만이기 때문에
# 시간복잡도가 O(NlogN) 이 되면 안된다고 판단했습니다.
# 따라서 M 의 입력을 받는 반복문을 제외하고
# 추가적인 반복문 없이 답을 찾을 수 있을까를 고민했습니다.
# 리스트의 i 번째부터 j 번째 까지의 부분 합을 구하는 문제이다보니
# 리스트의 요소에 각 n 번쨰의 숫자를 저장하는 것이 아니라
# n 번째까지 합을 요소로 갖고 있는 sums 리스트를 만들고,
# sums 리스트의 j - 1 번째에서 i - 2 번째를 빼주면 되지 않을까?
# 라고 생각했습니다.
# 그런데, i 가 1 인 경우에는 i - 2 를 하게 되면,
# 리스트의 맨 뒤에 값으로 넘어가게되서, 따로 조건문으로 예외처리를 해줘도 되지만,
