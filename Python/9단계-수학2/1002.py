# 백준 1002번 문제

n = int(input())
for i in range(0, n):
    x1, y1, r1, x2, y2, r2 = input().split()
    distance = ((int(x1)-int(x2))**2 + (int(y1)-int(y2))**2)**0.5
    if int(x1) == int(x2) and int(y1) == int(y2):
        if int(r1) == int(r2):
            print(-1)
        else:
            print(0)
    else:
        if int(r1) > int(r2):
            if int(r1) - int(r2) < distance < int(r1) + int(r2):
                print(2)
            elif distance == int(r1) + int(r2) or distance == int(r1) - int(r2):
                print(1)
            elif distance > int(r1) + int(r2) or distance < int(r1) - int(r2):
                print(0)
        elif int(r2) >= int(r1):
            if int(r2) - int(r1) < distance < int(r1) + int(r2):
                print(2)
            elif distance == int(r1) + int(r2) or distance == int(r2) - int(r1):
                print(1)
            elif distance > int(r1) + int(r2) or distance < int(r2) - int(r1):
                print(0)
