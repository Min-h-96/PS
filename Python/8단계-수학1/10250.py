# 백준 10250번 문제. ACM 호텔
import sys

T = int(sys.stdin.readline())

for t in range(T):
    H, W, N = map(int, sys.stdin.readline().split())
    if N % H == 0:
        print(str(H)+str((N-1)//H+1).zfill(2))
    else:
        print(str(N % H)+str((N-1)//H+1).zfill(2))

# 72ms
