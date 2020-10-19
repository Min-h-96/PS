# 백준 11650번 문제. 좌표 정렬 1
from math import log


def get_digit(number, d, base):
    return (number // base ** d) % base


def counting_sort_with_digit(A, d, base):
    k = base - 1
    B = [-1] * len(A)
    C = [0] * (k + 1)

    for a in A:
        C[get_digit(a, d, base)] += 1

    for i in range(k):
        C[i + 1] += C[i]

    for j in reversed(range(len(A))):
        B[C[get_digit(A[j], d, base)] - 1] = A[j]
        C[get_digit(A[j], d, base)] -= 1

    return B


def radix_sort(list, base=10):
    digit = int(log(max(list), base) + 1)

    for d in range(digit):
        list = counting_sort_with_digit(list, d, base)
    return list


if __name__ == "__main__":
    # Radix sort 이용해서 적용시켜야 함
