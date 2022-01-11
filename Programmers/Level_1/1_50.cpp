/* **************************************************************
    하샤드 수
************************************************************** */

#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int tmp = x;
    int sumOfDigit = 0;
    
    while (tmp > 0) {
        sumOfDigit += tmp % 10;
        tmp /= 10;
    }
    if (x % sumOfDigit != 0)
        answer = false;
    return answer;
}