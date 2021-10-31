/* **************************************************************
    체육복
************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int numOfDivisors(int n) {
    int num = 0;

    for (int i = 1; i * i <= n; i++) {
        if (i * i == n)
            num++;
        else if (n % i == 0)
            num += 2;
    }
    return num;
}

int solution(int left, int right) {
    int answer = 0;

    for (int i=left; i<=right; i++) {
        if (numOfDivisors(i) % 2 == 0)
            answer += i;
        else
            answer -= i;
    }
    return answer;
}