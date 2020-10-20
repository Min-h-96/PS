"""
Count sorting을 이용한 Radix Sorting
"""
from math import log


def get_digit(number, d, base):
    return (number // base ** d) % base


def counting_sort_with_digit(A, d, base):
    # k : ex) 10진수의 최대값 = 9
    k = base - 1
    B = [-1] * len(A)
    C = [0] * (k + 1)
    # 현재 자릿수를 기준으로 빈도수 세기
    for a in A:
        C[get_digit(a, d, base)] += 1

    # C 업데이트
    for i in range(k):
        C[i + 1] += C[i]

    # 현재 자릿수를 기준으로 정렬
    for j in reversed(range(len(A))):
        B[C[get_digit(A[j], d, base)] - 1] = A[j]
        C[get_digit(A[j], d, base)] -= 1

    return B


def radix_sort(list, base=10):
    # 입력된 리스트 가운데 최대값의 자릿수 확인
    digit = int(log(max(list), base) + 1)
    # 자릿수 별로 counting sort
    for d in range(digit):
        list = counting_sort_with_digit(list, d, base)
    return list


if __name__ == "__main__":
    lst = [123, 324, 313, 554, 427, 954, 394]
    print(radix_sort(lst))

    for i in reversed(range(len(lst))):
        print(i)
