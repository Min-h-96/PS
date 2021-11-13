/* **************************************************************
    짝수와 홀수
************************************************************** */

#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    if (num % 2 == 0)
        return "Even";
    else
        return "Odd";
}