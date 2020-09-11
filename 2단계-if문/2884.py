# 백준 2884번 문제. 알람 시계
H, M = map(int, input().split())
# 45 <= M < 60 이면 H 변화 x 단지 M - 45
# M < 45 이면 H - 1, M = 60 - 45 + M
if 45 <= M < 60:
    print(H, M-45)
elif M < 45 and H != 0:
    print(H-1, 60 - 45 + M)
elif M < 45 and H == 0:
    print(23, 60 - 45 + M)
