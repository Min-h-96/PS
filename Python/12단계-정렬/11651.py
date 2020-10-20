# 백준 11651번 문제. 좌표 정렬 2
import sys


def get_XY(list, d):
    return list[d]


def counting_sort_with_digit(A, d):
    # [[3, 4], [1, 1], [1, -1], [2, 2], [3, 3]]

    B = [-1] * len(A)
    C = [0] * 200001

    for a in A:
        C[get_XY(a, d) + 100000] += 1

    for i in range(200000):
        C[i + 1] += C[i]

    for j in reversed(range(len(A))):
        B[C[get_XY(A[j], d) + 100000] - 1] = A[j]
        C[get_XY(A[j], d) + 100000] -= 1

    return B


def radix_sort(list):
    digit = 2

    for d in range(digit):
        list = counting_sort_with_digit(list, d)
    return list


if __name__ == "__main__":
    N = int(sys.stdin.readline())

    locations = []

    for n in range(N):
        i = list(map(int, sys.stdin.readline().split()))
        locations.append(i)

    for locate in radix_sort(locations):
        print(locate[0], locate[1])

# 700ms 55840KB
