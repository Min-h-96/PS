# 백준 4673 번 문제. 셀프 넘버
def d(n):
    m = sum(map(int, str(n)))
    return n + m


def findSelfNum(n):
    lst = []
    for i in range(1, n+1):
        lst.append(d(i))

    for i in range(1, n+1):
        if i in lst:
            pass
        else:
            print(i)


findSelfNum(10001)

# 692ms
