/* **************************************************************
    예상 대진표
************************************************************** */

#include <iostream>
#include <stdlib.h>

using namespace std;

int solution(int n, int a, int b) {
    int answer = 0;

    while (abs(a - b) > 1 || (a % 2 == 0 && a + 1 == b) || (b % 2 == 0 && b + 1 == a)) {
        if (a % 2 != 0)
            a++;
        if (b % 2 != 0)
            b++;
        a /= 2;
        b /= 2;
        answer++;
    }
    answer++;

    return answer;
}