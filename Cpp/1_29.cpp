/* **************************************************************
    두 정수 사이의 합
************************************************************** */

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    if (a >= b)
        while (b <= a)
            answer += (long long)b++;
    else
        while (a <= b)
            answer += (long long)a++;
    return answer;
}