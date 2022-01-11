/* **************************************************************
    문자열 다루기 기본
************************************************************** */

#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    
    for (auto i : s) {
        if (!isdigit(i))
            answer = false;
    }
    if (s.size() != 4)
        answer = false;
    
    return answer;
}