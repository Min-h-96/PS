/* **************************************************************
    정수 제곱근 판별
************************************************************** */

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    
    if ((int)sqrt(n) == n / sqrt(n))
        answer = pow(sqrt(n) + 1, 2);
    else
        answer = -1;
    
    return answer;
}