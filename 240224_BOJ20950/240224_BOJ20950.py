# 미술가 미미_BOJ20950

import sys

N = int(sys.stdin.readline())
color = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
gom = list(map(int, sys.stdin.readline().split()))
visited = [False for _ in range(N)]
global answer
answer = 255 * 3

def back(r, g, b, cnt, start):
	global answer
	if (cnt > 1):
		mon = [r // cnt, g // cnt, b // cnt]
		answer = min(answer, abs(mon[0] - gom[0]) + abs(mon[1] - gom[1]) + abs(mon[2] - gom[2]))

	if (cnt == N or cnt == 7):
		return

	for i in range(start, N):
		if (visited[i]):
			continue
		visited[i] = True
		back(r + color[i][0], g + color[i][1], b + color[i][2], cnt + 1, i + 1)
		visited[i] = False

back(0, 0, 0, 0, 0)
print(answer)